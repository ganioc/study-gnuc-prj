#pragma once
#include <iostream>
#include <memory>

using namespace std;


template<class T, class A=allocator<T>>
class SimpleVector{
private:
    T* elem; // start of allocation
    T* space; // end of element sequence, start of space for possible expansion
    T* last; // end of allocated space
    A alloc; // allocator
public:
    using size_type = unsigned int; // type used for vector sizes
    explicit SimpleVector(size_type n, const T& val=T(), const A& a=A());
    SimpleVector(const SimpleVector& a); // copy constructor
    SimpleVector& operator=(const SimpleVector& a); // copy assignment
    SimpleVector(SimpleVector&&a); // move constructor
    SimpleVector& operator=(SimpleVector&& a); // move assignment
    ~SimpleVector();
    size_type size() const { return space-elem; }
    size_type capacity() const { return last-elem;}
    void reserve(size_type n); // increase capacity to n
    void resize(size_type n, const T& = {}); // increase size to n
    void push_back(const T&);
};
