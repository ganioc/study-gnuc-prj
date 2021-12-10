// the main entry of CPP programming language example programs

#include <iostream>
#include <thread>
#include <semaphore.h>
#include <vector>

#include "cpplang.h"
#include "ZeroEvenOdd.h"

using namespace std;

double read_and_sum(int s){
    vector<double> v = {};
    printf("v size is: %lu\n", v.size());
    // vector_int(v,s);
    for(int i =0; i<s; i++){
        double d;
        cin>>d;
        v.push_back(d);
    }
    printf("v size is: %lu\n", v.size());
    double sum = 0;
    for(int i=0; i<v.size(); i++){
        printf("%d %f\n", i, v.operator[](i));
        sum+= v.operator[](i);
    }

    return sum;
}

void lesson(){
    int v[]={0,1,2,3,4,5,6,7,8,9};

    for(auto x: v){
        cout << x << endl;
    }
    // cout << "lesson, please input numbers" << endl;
    // double sum = read_and_sum(3);
    // printf("sum is %f\n", sum);
}

int main()
{
    // cout << "Hello cpplang!" << endl;

    ZeroEvenOdd *mZeroEvenOdd = new ZeroEvenOdd(5);
    mZeroEvenOdd->run();

    // lesson();

    return 0;
}