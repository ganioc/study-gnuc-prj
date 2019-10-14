#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
void DisplayNums(vector<int>& dynArray) {
    for_each(dynArray.begin(), dynArray.end(),
	     [](int Element) { cout << Element << " "; });
    cout << endl;
}


int main() {
    cout << "hello do it" << endl;
    int someNums[] = {1, 101, -1, 40, 2040};

    for (int aNum : someNums) {
	cout << "Array element is : " << aNum << endl;
    }

	vector<int> myNums;
	myNums.push_back(501);
	myNums.push_back(-1);
	myNums.push_back(25);
	myNums.push_back(-35);

	DisplayNums(myNums);

	int* newInt = new int;
	*newInt = 120;

	cout << *newInt << endl;

	delete newInt;
	cout << "Free newInt variable" << endl;

	return 0;
}
