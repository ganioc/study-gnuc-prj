#pragma once


template<typename T>
struct X{
    int m1=7;
    T m2;
    X(const T&x): m2{x} {}
};


int template_main();


