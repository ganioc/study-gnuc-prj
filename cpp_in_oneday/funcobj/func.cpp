#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

template <typename elementType>
void FuncDisplayElement(const elementType& element) {
    cout << element << ' ';
};

template <typename elementType>
struct DisplayElement {
    void operator()(const elementType& element) const {
	cout << element << ' ';
    }
};

int main(){
    vector<int> numsInVec{0, 1, 2, 3, -1, -9, 0, -999};
    cout << "Vector of integers contans: " << endl;
    for_each(numsInVec.begin(), numsInVec.end(), DisplayElement<int>());

    list<char> CharsInList{'a', 'z'};
    cout << endl << "List of characters contains: " << endl;

    for_each(CharsInList.begin(), CharsInList.end(), DisplayElement<char>());

    return 0;
}
