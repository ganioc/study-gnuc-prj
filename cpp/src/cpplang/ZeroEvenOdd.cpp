#include <iostream>
#include <thread>
#include <unistd.h>
#include <fcntl.h>

#include "ZeroEvenOdd.h"

using namespace std;

ZeroEvenOdd::ZeroEvenOdd(int n)
{
    this->n = n;
    sem_unlink("zero");
    sem_zero = sem_open("zero", O_CREAT | O_EXCL, 0644, 0);

    if(sem_zero == SEM_FAILED){
        cout << "sem_open() failed" << endl;
    }
    sem_unlink("even");
    sem_even = sem_open("even", O_CREAT | O_EXCL, 0644, 0);
    if(sem_even == SEM_FAILED){
        cout << "sem_open() failed" << endl;
    }
    sem_unlink("odd");
    sem_odd = sem_open("odd", O_CREAT | O_EXCL, 0644, 0);
    if(sem_odd == SEM_FAILED){
        cout << "sem_open() failed" << endl;
    }
    // sem_init(sem_zero, 0 ,0);
    // sem_init(sem_even, 0, 0);
    // sem_init(sem_odd, 0, 0);
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
        printf("%d", 0);

        sem_post(sem_even);
        //printf("after sem_post zero->even\n");

        //printf("before sem_wait zero\n");
        sem_wait(sem_zero);
        //printf("after sem_wait zero\n");
        // sleep(1);
        
    }
    //sleep(1);
}
void ZeroEvenOdd::even(int printNumber)
{
    for (int i = 1; i <= printNumber; i++)
    {
        //printf("before sem_wait even\n");
        sem_wait(sem_even);
        //printf("after sem_wait even\n");
        if (i % 2 == 0)
        {
            // cout << "even" << i;
            printf("%d", i);
        }

        sem_post(sem_odd);
        //printf("after sem_post even->odd\n");
        // 
    }
    //sleep(1);
}
void ZeroEvenOdd::odd(int printNumber)
{
    for (int i = 1; i <= printNumber; i++)
    {
        //printf("before sem_wait odd\n");
        sem_wait(sem_odd);
        //printf("after sem_wait odd\n");
        if ( i % 2 == 1)
        {
            // cout << "odd" << i;
            printf("%d", i);
        }
        sem_post(sem_zero);
        //printf("after sem_post odd->zero\n");
        // sleep(1);
    }
    //sleep(1);
}
void ZeroEvenOdd::run()
{
    cout << "-- run()" << endl;

    thread thread1([this](){
        zero(this->n);
    });
    thread thread2([this](){
        even(this->n);
    });
    thread thread3([this](){
        odd(this->n);
    });
    
    
    thread1.join();
    thread2.join();
    thread3.join();


    // sleep(2);

    cout << endl;

    cout << "-- end of run()" << endl;
}