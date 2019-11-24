#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

int main() {
    cout << "Enter an interger: ";
    int input = 0;
    cin >> input;

    stringstream converterStream;
    converterStream << input;
    string inputAsStr;
    converterStream >> inputAsStr;

    cout << "Integer Input = " << input << endl;
    cout << "String gained from interger = " << inputAsStr << endl;

    return 0;
}



