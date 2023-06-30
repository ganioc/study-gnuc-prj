#include <iostream>
#include "init.h"
#include "main.h"
#include "study.h"

using std::cout;
using std::endl;
// d s susing Nbk;

int main(){
    cout << "Hello Nbk\n";
    cout << SEPARATOR_LINE <<endl;
    cout << "Author: " << AUTHOR << endl;
    cout << "Version: " << VERSION << endl;
    cout << SEPARATOR_LINE << endl;

    Nbk::init_dir("./build/");

    STUDY::testAlg();

    return 0;
}