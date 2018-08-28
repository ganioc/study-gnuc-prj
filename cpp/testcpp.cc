#include <iostream>
#include <vector>
#include <bitset>
#include "GT.h"
#include <functional>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    cout << "testcpp running" << endl;

    string s1;
    string s2("value");
    string s3(5, '-');

    s1 = "hello world";

    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;

    cout << endl
         << s2.size() << endl;
    cout << s1 + s2 + s3 << endl;
    cout << s2[s2.size() - 1] << endl;
    // unsigned type
    string::size_type index = 0;
    cout << isalnum('a') << endl;

    for (string::size_type index = 0; index != s1.size(); ++index)
    {
        s1[index] = toupper(s1[index]);
    }
    cout << "To upper case:" << s1 << endl;

    vector<int> ivec;
    vector<int> ivec4(10, -1);
    vector<int>::iterator iter = ivec4.begin();

    cout << ivec4[0] << endl;
    for (vector<int>::iterator iter = ivec4.begin();
         iter != ivec4.end();
         ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    bitset<16> bitvec1(0xffff);
    cout << bitvec1 << endl;

    string strval("1100");
    bitset<32> bitvec4(strval);
    cout << bitvec4 << endl;

    string str("1111111000000011001101");
    bitset<32> bitvec5(str, 5, 5);
    bitset<32> bitvec6(str, str.size() - 5);
    cout << bitvec5 << "-" << bitvec6 << endl;
    cout << bitvec5.size() << "-" << bitvec6.count() << endl;

    int someNum(100);
    cout << "some number:" << someNum << endl;

    // search value
    int search_value = 42;
    vector<int> ivec5(10, -1);
    // vector<int> vec(12,13,14);

    vector<int> vec = {1, 2, 3, 1000, 4, 5};

    cout << "I'm trying:" << less_equal<int>()(15, 11) << endl;
    // cout << std::bind(less_equal<int>(), 10)(4) << endl;
    auto f = bind(less_equal<int>(), 34, placeholders::_1);
    cout << "23 is less than 34:" << f(23) << endl;
    cout << "55 is less than 34:" << f(55) << endl;

    auto f1 = less<int>();
    cout << "After negate f() function" << endl;
    cout << "23 is less than 34:" << f1(23, 34) << endl;
    cout << "55 is less than 34:" << f1(55, 34) << endl;

    return 0;
}