#include <iostream>
#include <vector>

using namespace std;

int testLoop() {
    int someNums[] = {1, 101, -1, 40, 2040};
    const int MyInts[3][2] = {{1, 2}, {3, 4}, {5, 6}};

    for (int aNum : someNums) {
	cout << "the array element are " << aNum << endl;
    }
    for (auto row : MyInts) {
	cout << row << endl;
    }

    return 0; }


int main() {
    vector<int> dynArray(3);

    dynArray[0] = 2;
    dynArray[1] = -234;
    dynArray[2] = 9;

    cout << "Number of integers in array: " << dynArray.size() << endl;
    dynArray.push_back(100);

    cout << "Number of new size: " << dynArray.size() << endl;
    cout << dynArray[dynArray.size() - 1] << endl;

    string greetString("Hello string");

    cout << greetString << endl;

    testLoop();

    return 0;
}
	
