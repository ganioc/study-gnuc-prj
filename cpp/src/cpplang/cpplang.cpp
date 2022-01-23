// the main entry of CPP programming language example programs

#include <iostream>
#include <thread>
#include <semaphore.h>
#include <vector>
#include <map>
#include <fstream>
#include <mutex>

#include <regex>
#include <numeric>
#include <list>
#include <random>
#include <limits>

#include "cpplang.h"
#include "ZeroEvenOdd.h"
#include "CVector.h"

using namespace std;
using namespace std::chrono;

double read_and_sum(int s)
{
    vector<double> v = {};
    printf("v size is: %lu\n", v.size());
    // vector_int(v,s);
    for (int i = 0; i < s; i++)
    {
        double d;
        cin >> d;
        v.push_back(d);
    }
    printf("v size is: %lu\n", v.size());
    double sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        printf("%d %f\n", i, v.operator[](i));
        sum += v.operator[](i);
    }

    return sum;
}

void lesson()
{
    int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (auto x : v)
    {
        cout << x << endl;
    }
    // cout << "lesson, please input numbers" << endl;
    // double sum = read_and_sum(3);
    // printf("sum is %f\n", sum);
}

void hello()
{
    cout << "Hello Concurrent World" << endl;
}
template <typename C, typename V>
vector<typename C::iterator> find_all(C &c, V v)
{
    vector<typename C::iterator> res;
    for (auto p = c.begin(); p != c.end(); ++p)
    {
        if (*p == v)
            res.push_back(p);
    }
    return res;
}
void test_iterator()
{
    cout << "Test iterator" << endl;
    string from, to;
    cin >> from >> to;

    ifstream is{from}; // input stream for file "from"
    istream_iterator<string> ii{is};
    istream_iterator<string> eos{};

    ofstream os{to};
    ostream_iterator<string> oo{os, "\n"};

    vector<string> b{ii, eos};
    sort(b.begin(), b.end());

    unique_copy(b.begin(), b.end(), oo);
}
void container()
{
    cout << "Test Container()" << endl;
    map<string, int> phone_book{
        {"David Hume", 1234},
        {"Karl Popper", 2345},
        {"Bertrand Arthur William Russell", 3456}};
    cout << phone_book.size() << endl;
    // for(auto p=phone_book.begin(); p!=phone_book.end(); ++p){
    //     cout << (*p) << endl;
    // }
    auto p = phone_book.begin();
    for (; p != phone_book.end(); ++p)
    {
        cout << p->first << " ";
        cout << p->second << endl;
    }

    vector<string> vs = {"red", "blue", "green", "green", "orange", "green"};
    for (auto p : find_all(vs, "green"))
        if (*p != "green")
            cerr << "vector bug!\n";

    for (auto p : find_all(vs, "green"))
        *p = "vert";

    for (auto p = vs.begin(); p != vs.end(); ++p)
        cout << *p << endl;

    ostream_iterator<string> oo{cout};

    *oo = "Hello,";
    ++oo;
    *oo = "world\n";

    test_iterator();
}
bool has_c(const string &s, char c)
{
    auto p = find(s.begin(), s.end(), c);
    if (p != s.end())
        return true;
    else
        return false;
}
void f(vector<double> &v, double *res)
{
    cout << "f is running" << endl;
    for (auto p = v.begin(); p != v.end(); ++p)
    {
        cout << *p << " ";
    }
    cout << endl;
    *res = 1.1;
};
struct F
{
    vector<double> &v;
    double *res;
    F(vector<double> &vv, double *p) : v{vv}, res{p} {};
    void operator()()
    {
        cout << "Parallel World F!\n";
        for (auto p = v.begin(); p != v.end(); ++p)
        {
            cout << *p << " ";
        }
        cout << endl;
        *res = 2.1;
    };
};
void parallel()
{
    cout << "Test parallelling" << endl;
    vector<double> some_vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<double> vec2{10, 11, 12, 13, 14};
    double res1;
    double res2;
    mutex m;

    thread t1([&]()
              {
                  unique_lock<mutex> lck{m};
                  f(some_vec, &res1);
              });
    thread t2([&]()
              {
                  F f(vec2, &res2);
                  unique_lock<mutex> lck{m};
                  f();
              });

    t1.join();
    t2.join();
    cout << "res1: " << res1 << " ";
    cout << "res2: " << res2 << endl;

    auto time0 = high_resolution_clock::now();
    this_thread::sleep_for(milliseconds{20});
    auto time1 = high_resolution_clock::now();
    cout << duration_cast<nanoseconds>(time1 - time0).count();
    cout << " nanoseconds passed." << endl;
}

void math(){
    list<double> lst {1,2,3,4,5,99};
    auto s = accumulate(lst.begin(), lst.end(), 0.0);
    cout << "Math: " << s << endl;

    // random()
    // Rand_int rnd{1,10};
    auto die = bind(uniform_int_distribution<>{1,6}, 
            default_random_engine{});
    int x = die();
    cout << "Generated number x: " << x << endl;
    int y = die();
    cout << "Generated number y: " << y << endl;

    static_assert(numeric_limits<char>::is_signed, "unsigned characters!");
    static_assert(100000 < numeric_limits<int>::max(), "small ints!");
}
void declare(){
    int count{1};
    const char * name {"Bjarne"};
    count = 2;
    name = "Marian";

    enum T { A, B, C, D};
    int x3 {3};
    printf("declare: %d\n", x3);
    vector<int> v1{99,98,97};
    // nullprt, 

}
void pointer(){
    int n = 2;
    void* pv;
    pv = &n;
    int *pi2 = static_cast<int *>(pv);
    cout << "pointer: " << *pi2 << endl;

    int *pi = nullptr;
    double* pd = nullptr;

    cout << "sizeof \"Bohr\":" << sizeof("Bohr") <<endl;
    char alpha[] = "abcdefg" 
                    "ABCDEFG";
    cout << "string alpha:" << alpha << endl;

    cout << R"(\w\\w)" << endl;

    string counts {R"(1
        22
        333)"};
    cout << "counts: " << counts << endl;

}
template<typename T>
int byte_diff(T*p, T* q){
    return reinterpret_cast<char*>(q) - reinterpret_cast<char*>(p);
}
void diff_test(){
    int vi[10];
    short vs[10];
    cout << vi << ' ' << &vi[1] << ' ' << &vi[1] - &vi[0] << ' '
        << byte_diff(&vi[0], &vi[1]) << '\n';
    cout << vs << ' ' << &vs[1] << ' ' << &vs[1] - &vs[0] << ' '
        << byte_diff(&vs[0], &vs[1]) << '\n';
}
int main()
{
    // cout << "Hello cpplang!" << endl;

    ZeroEvenOdd *mZeroEvenOdd = new ZeroEvenOdd(5);
    mZeroEvenOdd->run();

    // lesson();

    thread t(hello);
    t.join();

    CVector v(6);
    cout << "CVector:";
    cout << v.size() << endl;

    Color color = Color::blue;
    Traffic_light light = Traffic_light::green;
    // std::bitset<16> xColor(color);

    cout << "Color:";
    cout << as_integer(color) << endl;

    // std::bitset<16> xLight(light);

    cout << "Traffic_light:";
    cout << as_integer(light) << endl;
    ++light;
    cout << "Traffic_light ++:";
    cout << as_integer(light) << endl;

    const int speed = 100;

    static_assert(speed < 199, "Can't be that big!");

    string s{"C++ is a general purpose programming language"};
    cout << s << endl;

    // container();

    parallel();

    tuple<string, int, double> t2("Solid",12,3.14);

    auto tup = make_tuple("Herring", 10 ,1.23);
    cout << "tuple ";
    cout << get<0>(tup) << " ";
    cout << get<1>(tup) << " ";
    cout << get<2>(tup) << endl;

    regex pat(R"(\w{2}\s*\d{5}(-\d{4})?)");
    // cout << "pattern: " << pat << endl;
    math();

    declare();

    pointer();

    diff_test();
    
    return 0;
}