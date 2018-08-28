#include <iostream>
#include <vector>
#include <algorithm>
#include "CMessage.h"
#include "Folder.h"

int main()
{
    using namespace std;

    cout << "hi testfan.cc" << std::endl;
    vector<char> vec = {1, 2, 3, 4};
    int search_value = 45;

    vector<char>::const_iterator iter;
    iter = find(vec.begin(), vec.end(), search_value);

    cout << "The value " << search_value
         << ((iter == vec.end()) ? " is not present." : " is present.")
         << endl;

    for (int i : vec)
    {
        cout << i << ";" << endl;
    }

    enum class apple
    {
        green,
        red
    };
    cout << (apple::green == apple::red) << endl;
    cout << "hi! End." << endl;

    cout << "Test CMessage Class implementation" << endl;
    string s1 = "hello";
    string s2 = "world";

    CMessage m1(s1);
    CMessage m2(s2);

    Folder f1;
    Folder f2;

    m1.save(f1);
    m2.save(f1);
    m2.save(f2);

    m1.debug_print();
    m2.debug_print();

    f1.debug_print();
    f2.debug_print();

    f1.remove(m2);

    f1.debug_print();
    f2.debug_print();

    return 1;
}