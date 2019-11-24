#include <exception>
#include <iostream>
#include <string>

using namespace std;

class CustomException : public exception {
    string reason;

public:
    CustomException(const char* why) : reason(why) {}

    virtual const char* what() const throw() { return reason.c_str(); }
};

double Divide(double dividend, double divisor) {
    if (divisor == 0)
	throw CustomException("CustomException: Dividing by 0 is a crime");
    return (dividend / divisor);
}

int main() {
    double dividend = 100;
    double divisor = 0;

    try {
	cout << "Result is: " << Divide(dividend, divisor);
    } catch (exception& exp) {
	cout << exp.what() << endl;
	cout << "Sorry, can't continue!" << endl;
    }
    return 0;
}




