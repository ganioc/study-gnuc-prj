#include "../include/apue.h"
#include <stdio.h>
#include <unistd.h>
#include <setjmp.h>

static jmp_buf env_alrm;

static void sig_alarm(int signo)
{
    longjmp(env_alrm, 1);
}

unsigned int
sleep2(unsigned int seconds)
{
    if (signal(SIGALRM, sig_alarm) == SIG_ERR)
    {
        return (seconds);
    }
    if (setjmp(env_alrm) == 0)
    {
        alarm(seconds);
        pause();
    }
    return (alarm(0));
}

int main()
{
    printf("Hello\n");
    sleep2(1);
    return 0;
}