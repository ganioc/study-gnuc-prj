#include "Assoc.h"

int& Assoc::operator[](const string& s){
    for(auto x: vec){
        if(s == x.first)
            return x.second;
    }

    vec.push_back({s,0});

    return vec.back().second;
}