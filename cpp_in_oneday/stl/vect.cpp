#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> intArray;

    intArray.push_back(50);
    intArray.push_back(290);
    intArray.push_back(23);
    intArray.push_back(999);

    cout << "The contents of the vector are: " << endl;

    vector<int>::iterator arrIterator = intArray.begin();

    while (arrIterator != intArray.end()) {
	cout << *arrIterator << endl;
	++arrIterator;
    }
    vector<int>::iterator elFound = find(intArray.begin(), intArray.end(), 290);

    if (elFound != intArray.end()) {
	int elPos = distance(intArray.begin(), elFound);
	cout << "Value " << *elFound;
	cout << " found in the vector at position: " << elPos << endl;
    }

    cout << "Length of wchar_t : " << sizeof(wchar_t) << endl;
}
