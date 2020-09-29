#include "../include/apue.h"
#include <stdio.h>
#include <unistd.h>

static void sig_alarm(int signo)
{
}

unsigned int
sleep1(unsigned int seconds)
{
    if (signal(SIGALRM, sig_alarm) == SIG_ERR)
    {
        return (seconds);
    }
    alarm(seconds);
    pause();
    return (alarm(0));
}

int main()
{
    printf("Hello\n");
    sleep1(1);
    return 0;
}
