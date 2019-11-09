#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid;  // sub process id
    int status;
    pid = fork();

    if (pid < 0) {
	printf("fork err\n");
	exit(-1);
    } else if (pid == 0) {
	// child
	sleep(60);

	int a = 10;
	int b = 100;
	int c = 0;
	int d;
	printf("I am child process\n");

	d = b / a;
	printf("d = %d\n", d);
	d = a / c;
	printf("d = %d\n", d);  // division error

	exit(0);

    } else {
	// parent
	printf("I am parent process\n");
	sleep(4);
	printf("After sleep 4 seconds\n");
	wait(&status);  // wait child process to exit
	printf("exit parent process\n");
	exit(0);
    }
    return 0;
}


