#include "../include/apue.h"
#include <stdio.h>

int globvar = 6;
char buf[] = "a write to otdout\n";

int main(void)
{
    printf("This is mytry main()\n");

    pid_t pid;
    int var;

    var = 88;
    if(write(STDOUT_FILENO, buf, sizeof(buf) -1) != sizeof(buf) -1){
        err_sys("write error");
    }
    printf("before fork\n");

    if((pid= fork()) < 0){
        err_sys("fork error");
    }else if(pid ==0){
        globvar++;
        var++;
    }else{
        sleep(2);
    }
    printf("pid=%ld, glob=%d, var=%d\n", (long)getpid(), globvar, var);

    return 0;
}
