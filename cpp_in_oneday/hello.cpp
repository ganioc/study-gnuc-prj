#include <iostream>
#include "task.hpp"

using namespace std;
using namespace taskspace;

int main()
{
    std::cout << "hello world" << std::endl;
    cout << "magic number is :" << taskspace::magicNumber << endl;

    Task task("Alice", 14);

    task.Talk("Go go go!");
    task.IntroduceSelf();

    std::cout << std::endl;

    cout << "magic number is :" << magicNumber << endl;

    return 0;
}