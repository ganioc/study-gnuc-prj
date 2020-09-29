#include "task.hpp"

using namespace taskspace;

Task::Task(string myName, int myAge)
{
    this->age = myAge;
    this->name = myName;
    this->gender = "Girl";
}

void Task::Talk(string textToTalk)
{

    cout << "I say: " << textToTalk << endl;
}

void Task::IntroduceSelf(void)
{
    cout << "I am " << this->name << " " << this->age << endl;
    cout << endl
         << "Modify magicNumber in Task::Task()" << endl;
    magicNumber = 19;
    cout << "magicNumber=" << magicNumber << endl;
}