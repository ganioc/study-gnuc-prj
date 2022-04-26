#pragma once

#include<vector>
#include<string>

using namespace std;

struct Assoc{
    vector<pair<string,int>> vec;

    const int& operator[](const string&) const;
    int& operator[](const string&);
};

