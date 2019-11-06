#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <set>
#include <vector>

using namespace std;

template <typename T>
void displayAsContents(const T& container) {
    for (auto element = container.cbegin(); element != container.cend();
	 ++element) {
	cout << *element << "  ";
    }

    cout << endl;
}
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

    // char* dynamicName = new char[12];
    const char* constCStyleString = "Hello string!";
    string strFromConst(constCStyleString);

    string str2("Hello string2");

    cout << strFromConst << endl;
    cout << str2 << endl;

    string strPartialCopy(strFromConst, 6);
    cout << strPartialCopy << endl;

    string strRepeatChars(10, 'x');
    cout << strRepeatChars << endl;

    cout << endl << "Display elements in string " << endl;
    for (size_t charCounter = 0; charCounter < strPartialCopy.length();
	 charCounter++) {
	cout << "Character [" << charCounter << "] is: ";
	cout << strPartialCopy[charCounter] << endl;
	}

	int charOffset = 0;
	//	string::const_iterator charLocator;
	for(auto charLocator = strPartialCopy.cbegin();
			charLocator != strPartialCopy.cend();
			++charLocator){
		cout << "Character [" << charOffset++ << "] is: ";
		cout << *charLocator << endl;

	}
	cout << endl;

	cout << strPartialCopy.c_str() << endl;

	string sampleStr1("No");
	sampleStr1 += sampleStr1;

	sampleStr1.append(" Go");
	cout << sampleStr1 << endl;

	size_t charPosition = strPartialCopy.find("str", 0);
	if (charPosition != string::npos) {
	    cout << "First instance of ll was found at position "
		 << charPosition << endl;
	} else {
	    cout << "Substring not found" << endl;
	}

	string samplestr3("hello string, wake up to a beautiful day!");
	samplestr3.erase(13, 25);
	cout << samplestr3 << endl;
	reverse(samplestr3.begin(), samplestr3.end());

	cout << samplestr3 << endl;

	transform(samplestr3.begin(), samplestr3.end(), samplestr3.begin(),
		  ::toupper);

	cout << samplestr3 << endl;

	string timeinText = "100";
	cout << timeinText << endl;

	vector<int> dynIntArray;
	dynIntArray.push_back(1);
	dynIntArray.push_back(2);
	dynIntArray.push_back(100);
	dynIntArray.push_back(101);
	dynIntArray.push_back(102);

	vector<int>::iterator iter;
	for (iter = dynIntArray.begin(); iter != dynIntArray.end(); ++iter) {
	    cout << *iter << endl;
	}
	cout << dynIntArray.size() << endl;
	cout << dynIntArray.capacity() << endl;

	deque<int> intDeque;
	intDeque.push_back(3);
	intDeque.push_front(22);

	for (auto iter = intDeque.cbegin(); iter != intDeque.cend(); ++iter) {
	    cout << *iter << endl;
	}

	list<float> floatList = {12, 3, 3, 4.4, 5.6};
	floatList.insert(floatList.begin(), 55.55);
	displayAsContents<list<float>>(floatList);

	floatList.reverse();
	displayAsContents<list<float>>(floatList);

	set<int> setInts;
	setInts.insert(-1);
	setInts.insert(0);
	setInts.insert(1);

	cout << endl;
	displayAsContents<set<int>>(setInts);

	auto eleFound = setInts.find(-1);
	if (eleFound != setInts.end()) {
	    cout << "-1 found in setInts" << endl;
	}
	return 0;
}

