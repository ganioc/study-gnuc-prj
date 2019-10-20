#include <iostream>
#include "derive.hpp"
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
void testDerive() {
    Carp myLunch;
    Tuna myDinner;

    cout << "About my food:" << endl;
    cout << "Lunch: ";
    myLunch.Swim();

    cout << "Dinner: ";
    myDinner.Swim();
    myDinner.Fish::Swim();
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

    testDerive();

    return 0;
}
