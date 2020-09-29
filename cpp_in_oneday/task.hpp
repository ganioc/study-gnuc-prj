#include <iostream>

using namespace std;

namespace taskspace{
    static int magicNumber=10;
}

class Task
{
private:
    string name;
    string gender;
    int age;

public:
    Task(string myName, int myAge);
    void Talk(string textToTalk);
    void IntroduceSelf(void);
};