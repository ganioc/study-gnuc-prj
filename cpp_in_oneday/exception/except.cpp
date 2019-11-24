#include <exception>
#include <iostream>

using namespace std;

double Divide(double dividend, double divisor) {
    if (divisor == 0) {
	throw "Dividing by 0 is a crime";
    } else {
	return dividend / divisor;
    }
}
int main() {
    cout << "Enter number of integers you wish to reserve: ";

    try {
	int input = 0;
	cin >> input;

	int* numArray = new int[input];
	delete[] numArray;
    } catch (bad_alloc& excep) {
	cout << "Exception encoutered: " << excep.what() << endl;
	cout << "Got to end, sorry!" << endl;
    } catch (...) {
	cout << "Eception encoutered. Go to end, sorry!" << endl;
	}

	double divident = 4.0;
	double divisor = 2.0;

	try {
	    cout << "Result is: " << Divide(divident, divisor);
	} catch (const char* exp) {
	    cout << "Exception: " << exp << endl;
	    cout << "Sorry, can't continue!" << endl;
	}
	cout << endl;

	return 0;
}
