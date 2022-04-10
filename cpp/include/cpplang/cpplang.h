#pragma once

#define AUTHOR_NAME yango

using namespace std;

enum class Color { red, blue, green};
enum class Traffic_light { green , yellow, red, white};

Traffic_light & operator++(Traffic_light & t){
    switch(t){
        case Traffic_light::green: return t=Traffic_light::yellow;
        case Traffic_light::yellow: return t=Traffic_light::red;
        case Traffic_light::red: return t=Traffic_light::green;
    }
    return t=Traffic_light::white;
}

template <typename Enumeration>
auto as_integer(Enumeration const value) 
    -> typename std::underlying_type<Enumeration>::type    
{
    return static_cast<typename std::underlying_type<Enumeration>::type>(value);
}


