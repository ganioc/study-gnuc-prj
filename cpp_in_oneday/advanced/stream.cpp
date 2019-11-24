#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    cout << "Enter an integer: ";
    int input = 500;
    // cin >> input;

    cout << "Integer in octal: " << oct << input << endl;
    cout << "Integer in hexadecimal: " << hex << input << endl;
    cout << "Integer in hex using base notation: ";
    cout << setiosflags(ios_base::hex | ios_base::showbase |
			ios_base::uppercase);
    cout << input << endl;

    cout << "integer after resetting I/O flags: ";
    cout << resetiosflags(ios_base::hex | ios_base::showbase |
			  ios_base::uppercase);
    cout << input << endl;
	const double Pi = (double)22.0/7;
	cout << "Pi= " << Pi << endl;

	cout << endl << "setting precesion to 7: " << endl;
	cout << setprecision(7);
	cout << "Pi = " << Pi << endl;

	cout << fixed << "fixed Pi = " << Pi << endl;
	cout << scientific << "Scientific Pi = " << Pi << endl;

	cout << endl << "Setting precision to 10: " << endl;
	cout << setprecision(10);
	cout << "Pi = " << Pi << endl;

	double radius = 5.5;
	cout << "Area of circle: " << 2 * Pi * radius * radius << endl;

	cout << "Hey - default!" << endl;
	cout << setw(35);
	cout << "Hey - right aligned!" << endl;
	cout << setw(35) << setfill('*');
	cout << "Hey - right aligned!" << endl;

	cout << "Hey - back to default" << endl;

	ofstream myFile1;
	myFile1.open("HelloFile1.txt", ios_base::out);

	if (myFile1.is_open()) {
	    cout << "File open successful" << endl;
	    myFile1 << "My first text file!" << endl;
	    myFile1 << "Hello file!";

	    cout << "Finished writing to file, close now." << endl;
	    myFile1.close();
	}
	return 0;

}
