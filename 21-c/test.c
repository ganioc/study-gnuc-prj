#include <stdio.h>
#include <unistd.h> //sleep
#include <stdlib.h> // exit, _Exit, ...
#include <ctype.h>

void waitl()
{
    fprintf(stderr, "OOOOoooo\n");
}

void on_death()
{
    for (int i = 0; i < 4; i++)
    {
        fprintf(stderr, "I'm dead\n");
    }
}
// dont prepare info for function to return
// _Noreturn void the_count()
_Noreturn void the_count()
{
    for (int i = 5; i-- > 0;)
    {
        printf("%i\n", i);
        sleep(1);
    }
    //_Exit(1);
    exit(1);
}

int main(int argc, char **argv)
{
    int c;
    int aflag = 0;
    while ((c = getopt(argc, argv, "abc:")) != -1)
    {
        switch ((c))
        {
        case 'a':
            aflag = 1;
            /* code */
            break;

        default:
            break;
        }
    }
    printf("aflag=%d\n", aflag);

    int a = 3;
    // at_quick_exit(waitl);
    atexit(waitl);
    atexit(on_death);

    the_count();

    printf("Let's start\n");
    if (a < 4)
    {
        printf("a is less than 4\n");
    }
    else
    {
        goto out;
    }
    printf("Do some computation\n");
out:
    printf("Until now\n");
    return 0;
}