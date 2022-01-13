#pragma once
#include <iostream>

using namespace std;


enum class Kind:char{
    name,
    number,
    end,
    plus='+',
    minus='-',
    mul='*',
    div='/',
    print=';', // name, or something can be printed
    assign='=',
    lp='(',
    rp=')'
};

struct Token
{
    Kind kind;
    string string_value;
    double number_value;
    /* data */
};


