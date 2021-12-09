#include <semaphore.h>
#include <iostream>

class ZeroEvenOdd
{
private:
    int n;
    sem_t *sem_zero;
    sem_t *sem_even;
    sem_t *sem_odd;

public:
    ZeroEvenOdd(int n);
    ~ZeroEvenOdd();

    void zero(int printNumber);
    void even(int printNumber);
    void odd(int printNumber);

    void run();
};
