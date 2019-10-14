#include <iostream>
#include "human.h"
#include "mystring.h"
#include "president.h"

using namespace std;

void testString() {
    cout << "Stirng buffer " << endl;
    MyString sayHello("Hello from MyString class");

    cout << sayHello.GetLength() << endl;
    cout << sayHello.GetString() << endl;
}
void testPresident() {
    cout << "\nTest President" << endl;
    President& onlyPresident = President::GetInstance();
    onlyPresident.SetName("Abraham Lincoln");

    cout << President::GetInstance().GetName() << endl;
    //    President secondPresident;
}

int main() {
    Human firstMan;

    firstMan.dateOfBirth = "1970";
    firstMan.IntroduceSelf();

    firstMan.SetAge(18);
    firstMan.IntroduceSelf();

    //  firstMan.age = 21;

    cout << firstMan.GetAge() << endl;

    testString();
    testPresident();

    return 0;
}
