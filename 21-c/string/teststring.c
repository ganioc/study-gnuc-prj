#include <stdio.h>
#include <string.h>
#include <stdlib.h> // malloc, free
#include <unistd.h>

void get_strings(char const *in)
{
    char *cmd;
    int len = strlen("strings ") + strlen(in) + 1;
    cmd = malloc(len);
    snprintf(cmd, len, "strings %s", in);

    if (system(cmd))
    {
        fprintf(stderr, "something went wrong running %s.\n", cmd);
        free(cmd);
    }
}

int main(int argc, char **argv)
{
    get_strings(argv[1]);

    pid_t mypid = getpid();
    printf("myid:%d\n", mypid);
    pid_t myppid = getppid();
    printf("my parent id:%d\n", myppid);
}