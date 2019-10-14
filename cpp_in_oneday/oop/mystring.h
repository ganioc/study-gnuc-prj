#include <string.h>
#include <iostream>

using namespace std;

class MyString {
   private:
    char* buffer;

   public:
    MyString(const char* initString) {
	cout << "Invoking constructor" << endl;
	buffer = NULL;
	if (initString != NULL) {
	    buffer = new char[strlen(initString) + 1];
	    strcpy(buffer, initString);
	}
    }
    MyString(const MyString& copySource) {
	buffer = NULL;
	cout << "Copy constructor" << endl;
	if (copySource.buffer != NULL) {
	    buffer = new char[strlen(copySource.buffer) + 1];

	    strcpy(buffer, copySource.buffer);

	    cout << "buffer points to: 0x" << hex;
	    cout << (unsigned int*)buffer << endl;
	}
	}
    ~MyString() {
	cout << "Invoking destructor" << endl;
	delete[] buffer;
    }
    int GetLength() { return strlen(buffer); }
    const char* GetString() { return buffer; }
};
