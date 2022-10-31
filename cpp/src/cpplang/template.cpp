#include "template.h"
#include  <iostream>

// String <char> s1;

using namespace std;


int template_main(){
    cout << "hello template" << endl;

    X<int> xi {9};
    X<string> xs{"Rapperswil"};


    return 0;
}
