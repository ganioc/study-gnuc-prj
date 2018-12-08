#include <iostream>
#include <vector>
#include <bitset>
#include <functional>
#include <algorithm>
#include <set>
#include <deque>
#include <map>
#include <sstream>

using namespace std;

void test1()
{
    vector<int> coll1;
    vector<float> coll2;

    vector<int>::iterator pos = coll1.begin();

    for (int i = 0; i < 6; i++)
    {
        coll1.push_back(i + 1);
    }

    // reverse(pos, coll1.end());
    vector<int>::iterator itea = coll1.begin();

    cout << "-----------------------" << endl;
    while (itea != coll1.end())
    {
        cout << *(itea++) << endl;
    }

    vector<float> c(coll1.begin(), coll1.end());
    auto cite = c.begin();
    cout << "==================" << endl;
    while (cite != c.end())
    {
        cout << *(cite++) << endl;
    }

    cout << "++++++++++++++++++" << endl;
    int array[] = {2, 3, 17, 33, 45, 77};
    set<int> cset(array, array + sizeof(array) / sizeof(array[0]));
    auto aiter = cset.begin();
    while (aiter != cset.end())
    {
        cout << *(aiter++) << endl;
    }

    vector<string> vvector;
    vvector.reserve(5);
    vvector.push_back("Hello");
    vvector.push_back("how");
    vvector.push_back("are");
    vvector.push_back("you");
    vvector.push_back("?");

    copy(vvector.begin(), vvector.end(),
         ostream_iterator<string>(cout, " "));
    cout << endl;

    vvector.insert(find(vvector.begin(), vvector.end(), "?"), "always");
    vvector.back() = "!";

    copy(vvector.begin(), vvector.end(),
         ostream_iterator<string>(cout, ""));
    cout << endl;

    //cout << greater<int>(2,3) << endl;
    set<int, greater<int>> colset;
    auto iterset = colset.begin();
    for (int i = 0; i < 10; i++)
    {
        colset.insert(i);
    }
    cout << *(colset.lower_bound(3)) << endl;
    cout << *(colset.upper_bound(3)) << endl;

    cout << "************************" << endl;
    set<double> coldset;
    if (coldset.insert(3.3).second)
    {
        cout << "3.3 inserted" << endl;
    }
    if (coldset.insert(3.3).second)
    {
        cout << "3.3 inserted" << endl;
    }
    else
    {
        cout << "3.3 inserted fail, exists" << endl;
    }
    pair<set<double>::iterator, bool> status;

    auto value = 3.5;
    status = coldset.insert(value);
    cout << value;

    if (status.second)
    {
        cout << " inserted";
    }
    else
    {
        cout << " NOT inserted";
    }
    cout << " " << endl;

    cout << "&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
    multiset<int> colmul;
    multiset<int>::iterator itermul;
    for (int i = 0; i < 5; i++)
    {
        colmul.insert(i + 1);
    }

    itermul = colmul.find(3);
    if (itermul != colmul.end())
    {
        colmul.erase(itermul);
    }
    copy(colmul.begin(), colmul.end(),
         ostream_iterator<int>(cout, " "));

    typedef set<int, greater<int>> IntSet;
    IntSet colintset;
    colintset.insert(101);
    IntSet colintset2(colintset.begin(), colintset.end());

    map<string, float> colmap;
    map<string, float>::iterator itermap;

    for (auto i = 1; i < 5; i++)
    {
        pair<string, float> a;
        stringstream s1;
        s1 << i + 100;
        a.first = s1.str();
        a.second = i;

        colmap.insert(a);
    }
    // itermap = colmap.begin();
    cout << endl;
    for (itermap = colmap.begin(); itermap != colmap.end(); itermap++)
    {
        cout << "key:" << itermap->first << "\t"
             << "value:" << itermap->second << endl;
    }
    colmap.insert(map<string, float>::value_type("abc", 1.12));
    cout << "^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    for (itermap = colmap.begin(); itermap != colmap.end(); itermap++)
    {
        cout << "key:" << itermap->first << "\t"
             << "value:" << itermap->second << endl;
    }
}

int main()
{
    set<int, less<int>> coll1;
    deque<int> coll2;

    for (int i = 1; i <= 9; i++)
    {
        coll1.insert(i);
    }

    transform(coll1.begin(), coll1.end(),
              back_inserter(coll2),
              negate<int>());

    auto ite2 = coll2.begin();
    while (ite2 != coll2.end())
    {
        cout << *(ite2++) << endl;
    }

    test1();

    return 0;
}
