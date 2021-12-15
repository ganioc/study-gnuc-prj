#pragma once
#include <vector>

template<typename T>
class Vec: public std::vector<T>{
public:
    using vector<T>::vector; // using constructor from vector
    T& operator[](int i){
        return vector<T>::at(i);
    }
    const T& operator[](int i) const{
        return vector<T>::at(i);
    }

private:


}