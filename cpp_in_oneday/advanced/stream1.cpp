#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;
struct Human {
    Human(){};
    Human(const char* inName, int inAge, const char* inDOB) : age(inAge) {
	strcpy(name, inName);
	strcpy(DOB, inDOB);
    }
    char name[30];
    int age;
    char DOB[20];
};

int main() {
    ifstream myFile;
    myFile.open("HelloFile1.txt", ios_base::in);

    if (myFile.is_open()) {
	cout << "File open successful. It contains: " << endl;
	string fileContents;

	while (myFile.good()) {
	    getline(myFile, fileContents);
	    cout << fileContents << endl;
	}

	cout << "Finished reading file, will close now" << endl;
	myFile.close();
    } else {
	cout << "Open() failed: check if file is in right folder" << endl;
    }

    Human Input("Siddhartha Rao", 101, "May 1916");
    ofstream fsOut("MyBinary.bin", ios_base::out | ios_base::binary);

    if (fsOut.is_open()) {
	cout << "Writing one object of Human to a binary file" << endl;
	fsOut.write(reinterpret_cast<const char*>(&Input), sizeof(Input));
	fsOut.close();
    }
	ifstream fsIn("MyBinary.bin", ios_base::in|ios_base::binary);

	if (fsIn.is_open()) {
	    Human somePerson;
	    fsIn.read((char*)&somePerson, sizeof(somePerson));

	    cout << "Reading information from binary file: " << endl;
	    cout << "Name = " << somePerson.name << endl;
	    cout << "Age = " << somePerson.age << endl;
	    cout << "Date of Birth = " << somePerson.DOB << endl;
	}
	return 0;
}

