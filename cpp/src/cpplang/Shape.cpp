#include "Shape.h"
#include <iostream>

using namespace std;

bool Circle::intersect(const Shape& s)const {
    return s.intersect(*this);
}

bool Circle::intersect(const Circle& c) const{
    cout <<"intersect(circle,circle)\n";
    return true;
}

bool Circle::intersect(const Triangle& t) const {
    cout <<"intersect(circle,triangle)\n";
    return true;
}

bool Triangle::intersect(const Shape& s)const{
    return s.intersect(*this);
}
bool Triangle::intersect(const Circle& c)const{
    cout <<"intersect(triange,circle)\n";
    return true;
}
bool Triangle::intersect(const Triangle& t) const{
    cout <<"intersect(triangle,triange)\n";
    return true;
}

