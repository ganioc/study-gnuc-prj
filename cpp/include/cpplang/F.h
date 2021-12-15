#pragma once
#include <vector>

using namespace std;

class F{
public:
    F(const vector<double>& vv, double * p):v{vv}, res{p}{}
    void operator()(); // place result in *res
private:
    const vector<double>& v;
    double* res;
};