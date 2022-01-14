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
};

double error(const string& s);

extern int no_of_errors;
double prim(bool get);
double term(bool get);
double expr(bool get);

