#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "NameDataSet.h"

using namespace std;

string funcNameIt()
{
    return "My Name";
}

int main(int nNumberofArgs, char *pszArgs[])
{
    cout << "Hello cpp" << endl;

    cout << funcNameIt() << endl;

    NameDataSet *nName = new NameDataSet(101, "Mike", "John");

    nName->print();
    nName->printId();

    delete nName;

    cout << "end" << endl;
    return 0;
}