#include <iostream>
#include <vector>
#include <bitset>
#include <functional>
#include <algorithm>
#include <set>
#include <deque>
#include <map>
#include <sstream>
#include <iomanip>

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

    // Test map
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
template <class K, class V>
class value_equals
{
  private:
    V value;

  public:
    value_equals(const V &v) : value(v) {}
    // comparison
    bool operator()(pair<const K, V> elem)
    {
        return elem.second == value;
    }
};
void test6()
{
    cout << "\n\nTest chapt 6.31" << endl;
    map<string, float> colmap;
    map<string, float>::iterator iterColmap;

    colmap.insert(map<string, float>::value_type("otto", 23.3));
    colmap.insert(pair<string, float>("Mary", 41.0));
    colmap.insert(make_pair("John", 55.0));
    colmap["marry"] = 45.4;

    for (iterColmap = colmap.begin(); iterColmap != colmap.end(); iterColmap++)
    {
        cout << "key:" << iterColmap->first << "\t"
             << "value:" << iterColmap->second << endl;
    }

    cout << "\nTo delete \"otto\"" << endl;
    for (iterColmap = colmap.begin(); iterColmap != colmap.end();)
    {
        if (iterColmap->first == "otto")
        {
            colmap.erase(iterColmap++);
        }
        else
        {
            iterColmap++;
        }
    }
    for (iterColmap = colmap.begin(); iterColmap != colmap.end(); iterColmap++)
    {
        cout << "key:" << iterColmap->first << "\t"
             << "value:" << iterColmap->second << endl;
    }

    cout << endl;
    cout << "John is:" << colmap["John"] << endl;

    cout << "\nTest multimap" << endl;

    typedef multimap<string, string> StrStrMMap;
    StrStrMMap dict;
    dict.insert(make_pair("bee", "sting"));
    dict.insert(make_pair("fan", "wind"));
    dict.insert(make_pair("fan", "cool"));
    StrStrMMap::iterator iterDict;
    for (iterDict = dict.begin(); iterDict != dict.end(); iterDict++)
    {
        cout << " " << iterDict->first << " " << iterDict->second << endl;
    }

    typedef map<float, float> FloatFloatMap;
    FloatFloatMap ffColl;
    FloatFloatMap::iterator iterFfColl;

    ffColl[1] = 4;
    ffColl[2] = 5;
    ffColl[3] = 99;
    ffColl[4] = 12.3;
    ffColl[5] = 3.0;

    iterFfColl = ffColl.find(1.0);
    if (iterFfColl != ffColl.end())
    {
        cout << iterFfColl->first << ": " << iterFfColl->second << endl;
    }

    iterFfColl = find_if(ffColl.begin(), ffColl.end(),
                         value_equals<float, float>(3.0));

    if (iterFfColl != ffColl.end())
    {
        cout << iterFfColl->first << ": " << iterFfColl->second << endl;
    }

    cout << "\nEnd of Test chpt 6.31\n"
         << endl;
}
class RuntimeStringCmp
{
  public:
    enum cmp_mode
    {
        normal,
        nocase
    };

  private:
    const cmp_mode mode; // actual mode
    static bool nocase_compare(char c1, char c2)
    {
        return toupper(c1) < toupper(c2);
    }

  public:
    RuntimeStringCmp(cmp_mode m = normal) : mode(m)
    {
    }

    bool operator()(const string &s1, const string &s2) const
    {
        if (mode == normal)
        {
            return s1 < s2;
        }
        else
        {
            return lexicographical_compare(s1.begin(), s1.end(),
                                           s2.begin(), s2.end(), nocase_compare);
        }
    }
};
typedef map<string, string, RuntimeStringCmp> StringStringMap;
void fillAndPrint(StringStringMap &coll);
void test6_6()
{
    StringStringMap coll1;
    fillAndPrint(coll1);
    RuntimeStringCmp ignorecase(RuntimeStringCmp::nocase);
    StringStringMap coll2(ignorecase);
    fillAndPrint(coll2);
}
void fillAndPrint(StringStringMap &coll)
{
    coll["Deutschland"] = "Germany";
    coll["deutch"] = "German";
    coll["Haken"] = "snag";
    coll["Hund"] = "dog";

    StringStringMap::iterator pos;
    cout.setf(ios::left, ios::adjustfield);
    for (pos = coll.begin(); pos != coll.end(); ++pos)
    {
        cout << setw(15) << pos->first.c_str() << " "
             << pos->second << endl;
    }
    cout << endl;
}
// main entry function
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
    test6();
    test6_6();

    return 0;
}
