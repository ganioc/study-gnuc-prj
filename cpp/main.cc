#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

string funcNameIt()
{
    return "My Name";
}

int main(int nNumberofArgs, char *pszArgs[])
{
    cout << "Hello cpp" << endl;

    cout << funcNameIt() << endl;

    cout << "end" << endl;
    return 0;
}