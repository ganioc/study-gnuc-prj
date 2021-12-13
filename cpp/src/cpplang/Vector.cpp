#include "Vector.h"
#include <iostream>
// Vector v;
using namespace  std;


void vector_init(Vector& v, int s){
    v.elem = new double[s];
    v.sz =s;
}

double read_and_sum_vector(int s){
    Vector v;
    vector_init(v, s);

    for(int i=0; i<s; i++){
        cin >> v.elem[i];
    }

    double sum = 0;
    for(int i=0; i< s; i++){
        sum += v.elem[i];
    }

    return sum;
}