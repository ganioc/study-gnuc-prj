#include <iostream>
#include <string>

using namespace std;

// Declare a function
int DemoConsoleOutput(void);

int main() {
    // Call i.i. invoke the function
    DemoConsoleOutput();

    cout << "hello world" << endl;

    int inputNumber;
    cout << "Enter an integer: ";
    cin >> inputNumber;

    cout << "Enter your name: ";
    string inputName;
    cin >> inputName;

    cout << inputName << " entered " << inputNumber << endl;
    // Return a value to the OS
    return 0;
}

int DemoConsoleOutput() {
    cout << "This is a simple string literal" << endl;
    cout << "Writing number five: " << 5 << endl;

    return 0;
}

