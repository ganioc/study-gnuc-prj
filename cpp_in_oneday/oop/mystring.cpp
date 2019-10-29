#include <iostream>
using namespace std;

#include <string.h>

class MyString {
   private:
    char* buffer;

   public:
    MyString(const char* initialInput) {
	if (initialInput != NULL) {
	    buffer = new char[strlen(initialInput) + 1];
	    strcpy(buffer, initialInput);
	} else
	    buffer = NULL;
    }

    MyString& operator=(const MyString& copySource) {
	if ((this != &copySource) && (copySource.buffer != NULL)) {
	    if (buffer != NULL) delete[] buffer;

	    buffer = new char[strlen(copySource.buffer) + 1];
	    strcpy(buffer, copySource.buffer);
	}
	return *this;
    }

    operator const char*() { return buffer; }

    ~MyString() { 
		if(buffer != NULL)
		delete[] buffer; }

    char& operator[](int index) { 
		if(index < GetLength())
		    return buffer[index];
		else {
		    return buffer[0];
		}
    }

    int GetLength() const { return strlen(buffer); }

    void operator()(string input) const { cout << input << endl; }
};

int main() {
    MyString string1("hello");
    MyString string2(" world");

    cout << "Before assignment: " << endl;
    cout << string1 << string2 << endl;
    string2 = string1;
    cout << "After assignment string2=string1: " << endl;
    cout << string1 << string2 << endl;

    cout << "index of " << string2.GetLength() << endl;
    cout << string2[1] << endl;
    cout << string2[2] << endl;

    string2("Display the string.");

    return 0;
}
