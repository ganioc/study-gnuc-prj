#include <iostream>
#include <thread>
#include <unistd.h>

#include "ZeroEvenOdd.h"

using namespace std;

ZeroEvenOdd::ZeroEvenOdd(int n)
{
    this->n = n;
    sem_zero = sem_open("zero", O_CREAT | O_EXCL, 0644, 0);
    sem_even = sem_open("even", O_CREAT | O_EXCL, 0644, 0);
    sem_odd = sem_open("odd", O_CREAT | O_EXCL, 0644, 0);
    cout << "Init ZeroEvenOdd()" << endl;
}
ZeroEvenOdd::~ZeroEvenOdd()
{
    cout << "~ZeroEvenOdd()" << endl;
    sem_unlink("zero");
    sem_unlink("even");
    sem_unlink("odd");
}
void  ZeroEvenOdd::zero(int printNumber)
{
    for (int i = 1; i <= printNumber; i++)
    {
        cout << 0 <<endl;
        // sem_post(sem_even);
        // sem_wait(sem_zero);
    }
}
void ZeroEvenOdd::even(int printNumber)
{
    for (int i = 1; i <= printNumber; i++)
    {
        // sem_wait(sem_even);
        if (i != 0 && i % 2 == 0)
        {
            cout << i;
        }
        // sem_post(sem_odd);
    }
}
void ZeroEvenOdd::odd(int printNumber)
{
    for (int i = 1; i <= printNumber; i++)
    {
        // sem_wait(sem_odd);
        if (i != 0 && i % 2 == 1)
        {
            cout << i;
        }
        // sem_post(sem_zero);
    }
}
void ZeroEvenOdd::run()
{
    cout << "run()" << endl;

    std::thread thread1([this](){
        zero(this->n);
    });
    // thread thread2([this](){
    //     even(this->n);
    // });
    // thread thread3([this](){
    //     odd(this->n);
    // });
    thread1.join();

    sleep(2);

    cout << "end of run()" << endl;
}