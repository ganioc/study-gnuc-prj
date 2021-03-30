#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t pid;
    pid = getpid();
    printf("my pid is %d\n", pid);

    pid_t returnPid = fork();

    if(returnPid == 0){
        printf("Hi I'm the master\n");
        return 0;
    }else{
        printf("I 'm child with pid is %d\n", returnPid);
        return 0;
    }

    // pid = getpid();
    // if(pid < 0){
    //     printf("error creating child process.");
    //     exit(1);
    // }

    // if(pid > 0){
    //     printf("my child's pid is %d\n", pid);
    //     exit(0);

    // }else{
    //     printf("hello from child process, i am still running\n");
    // }
    return 0;
}