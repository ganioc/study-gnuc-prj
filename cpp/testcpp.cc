#include <iostream>
#include <vector>
#include <bitset>

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

    return 0;
}