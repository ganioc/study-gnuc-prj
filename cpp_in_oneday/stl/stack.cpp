#include <bitset>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

int main() {
    stack<int> numsInStack;

    stack<double> dblsInStack;

    stack<double, vector<double>> doublesStackedInVec;

    stack<int> numsInStackCopy(numsInStack);

    numsInStack.push(25);
    numsInStack.push(10);
    numsInStack.push(-1);
    numsInStack.push(5);

    cout << "Stack contains " << numsInStack.size() << " elements" << endl;
    while (numsInStack.size() != 0) {
	cout << "Popping topmost element: " << numsInStack.top() << endl;
	numsInStack.pop();
    }

    if (numsInStack.empty()) {
	cout << "Popping all elements , empty stack!" << endl;
    }

    queue<int> numsInQ;
    queue<double> dblsInQ;
    queue<double, list<double>> dblsInQInList;
    queue<int> copyQ(numsInQ);

    cout << "Inserting into queue" << endl;
    numsInQ.push(10);
    numsInQ.push(5);
    numsInQ.push(1);
    numsInQ.push(20);

    cout << "Element at front: " << numsInQ.front() << endl;
    cout << "Element at back: " << numsInQ.back() << endl;

    while (numsInQ.size() != 0) {
	cout << "Deleting Element: " << numsInQ.front() << endl;
	numsInQ.pop();
    }
    if (numsInQ.empty()) {
	cout << "The queue is now empty." << endl;
    }

    priority_queue<int> numsInPrioQ;
    priority_queue<double> dblsInPrioQ;
    priority_queue<int, deque<int>, greater<int>> numsInDescendingQ;

    priority_queue<int> copyPrioQ(numsInPrioQ);
    numsInPrioQ.push(10);
    numsInPrioQ.push(50);
    numsInPrioQ.push(12);
    numsInPrioQ.push(100);

    cout << "Deleting the " << numsInPrioQ.size() << " elements" << endl;
    while (!numsInPrioQ.empty()) {
	cout << "Deleting topmost element: " << numsInPrioQ.top() << endl;
	numsInPrioQ.pop();
    }
    numsInDescendingQ.push(10);
    numsInDescendingQ.push(0);
    numsInDescendingQ.push(1);
    numsInDescendingQ.push(20);

    cout << "Deleting " << numsInDescendingQ.size() << " elements" << endl;
    while (!numsInDescendingQ.empty()) {
	cout << "Deleting topmost element " << numsInDescendingQ.top() << endl;
	numsInDescendingQ.pop();
    }

    cout << "bitset" << endl;
    bitset<4> fourBits;
	bitset<5> fiveBits("10101");

	cout << "Initial contents of fourBits: " << fourBits << endl;
	cout << "Initial contents of fiveBits: " << fiveBits << endl;

	bitset<6> sixBits(0b100001);
	bitset<8> eightBits(255);
	cout << "Initial contesnts sixBits: " << sixBits << endl;
	cout << "Initial contents of eightBits: " << eightBits << endl;

	bitset<8> inputBits;
	inputBits.set(0, 1);
	inputBits.set(3, 1);

	cout << "inputBits: " << inputBits << endl;
	cout << "inputBits count: " << inputBits.count() << endl;
	inputBits.flip();
	cout << "inputBits size: " << inputBits.size() << endl;
	cout << "inputBits zeros: " << inputBits.size() - inputBits.count()
	     << endl;

	vector<bool> boolFlags1;
	vector<bool> boolFlags2(10, true);

	// cout << "boolFlags1: " << boolFlags1 << endl;
	// cout << "boolflags2: " << boolflags2 << endl;
	boolFlags1.push_back(true);
	boolFlags1.push_back(false);
	boolFlags1.push_back(true);

	for (size_t index = 0; index < boolFlags1.size(); index++) {
	    cout << boolFlags1[index] << ' ';
	}
	cout << endl;

	return 0;
}
