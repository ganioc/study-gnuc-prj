#include "SimpleVector.h"
#include <iostream>

using namespace std;

template<class T, class A>
SimpleVector<T, A>::SimpleVector(size_type n, const T&val, const A&a)
    :alloc{a} {
    elem = alloc.allocate(n);  // get memroy for elements

    iterator<T,A> p;

    try{
        std::iterator<T,A> end = elem+n;
        for(p = elem; p!= end; ++p){
            alloc.construct(p, val);
        }
        last = space = p;
    }catch(std::runtime_error &e){
        for(std::iterator<T,A> q = elem; q!=p; ++q){
            alloc.destroy(q);
        }
        alloc.deallocate(elem, n);
        throw;
    }

    
}