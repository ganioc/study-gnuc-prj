#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

void sig_int(int sig);

int GetHttpHeader(char *buff, char *header);

// print error
#define PRINTERROR(s) fprintf(stderr, "\nError at %s, errno = %d\n", s, errno)

int main() {
    int bytes_all = 0;
    char host_name[] = "www.sohu.com";
    int nRet;
    int sock_fd;
    struct sockaddr_in server_addr;
    struct hostent *host_entry;
    char strBuffer[2048] = {0};
    char strHeader[1024] = {0};

    signal(SIGINT, sig_int);

    sock_fd = socket(PF_INET, SOCK_STREAM, 0);
    if (sock_fd == -1) {
	PRINTERROR("socket()");
	return -1;
    }

    printf("host_name: %s\n", host_name);

    host_entry = gethostbyname(host_name);
    server_addr.sin_port = htons(80);
    server_addr.sin_family = PF_INET;
    server_addr.sin_addr = (*(struct in_addr *)(host_entry->h_addr_list));

    nRet = connect(sock_fd, (struct sockaddr *)&server_addr,
		   sizeof(struct sockaddr_in));

    if (nRet == -1) {
	PRINTERROR("connect()");
	close(sock_fd);
	return -1;
    }

    /* http request header message */
    sprintf(strBuffer, "GET / HTTP/1.1\r\n");
    strcat(strBuffer, "Accept */*\r\n");
    strcat(strBuffer, "Connection: Keep-Alive\r\n");

    // send http request
    nRet = send(sock_fd, strBuffer, strlen(strBuffer), 0);
    if (nRet == -1) {
	PRINTERROR("send()");
	close(sock_fd);
	return -1;
    }

    while (1) {
	nRet = recv(sock_fd, strBuffer, sizeof(strBuffer), 0);
	if (nRet == -1) {
	    PRINTERROR("recv()");
	    break;
	}

	bytes_all += nRet;

	if (0 == GetHttpHeader(strBuffer, strHeader)) {
	    printf("%s", strHeader);
	}

	if (nRet == 0) {
	    fprintf(stderr, "\n %d bytes received.\n", bytes_all);
	    break;
	}
	printf("%s", strBuffer);
    }

    close(sock_fd);

    return 0;
}

void sig_int(int sig) { printf("Ha ha, we get SIGINT!\n"); }

int GetHttpHeader(char *buff, char *header) {
    char *p, *q;

    int i = 0;

    p = buff;
    q = header;

    if (NULL == p) {
	return -1;
    }

    if (NULL == q) {
	return -1;
    }

    while ('\0' != (*p)) {
	q[i] = p[i];
	if ((p[i] == 0x0d) && (p[i + 1] == 0x0a) && (p[i + 2] == 0x0d) &&
	    (p[i + 3] == 0x0a)) {
	    q[i + 1] = p[i + 1];
	    q[i + 2] = p[i + 2];
	    q[i + 3] = p[i + 3];
	    q[i + 4] = 0;
	    return 0;
	}
	i++;
    }
    return -1;
}







