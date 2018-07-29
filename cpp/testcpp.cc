#include <iostream>
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

    cout <<endl<< s3.size() <<endl;

    return 0;
}