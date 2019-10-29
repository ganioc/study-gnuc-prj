#include <iostream>
#include <memory>
#include <sstream>
#include <string>

using namespace std;

class Date {
   private:
    int month, day, year;
    string dateInString;

   public:
    Date(int inMonth, int inDay, int inYear)
	: month(inMonth), day(inDay), year(inYear){};
    Date& operator++() {
	++day;
	return *this;
    }
    Date& operator--() {
	--day;
	return *this;
    }
    void DisplayDate() {
	cout << month << " / " << day << " / " << year << endl;
    }
    operator const char*() {
	ostringstream formattedDate;
	formattedDate << month << " / " << day << " / " << year;
	dateInString = formattedDate.str();
	return dateInString.c_str();
    }
    explicit operator int() { return day + month + year; }
    Date operator+(int daysToAdd) {
	Date newDate(month, day + daysToAdd, year);
	return newDate;
    }
    Date operator-(int daysToSub) { return Date(month, day - daysToSub, year); }
    void operator+=(int daysToAdd) { day += daysToAdd; }
    void operator-=(int daysToSub) { day -= daysToSub; }
    bool operator==(const Date& compareTo) {
	return ((day == compareTo.day) && (month == compareTo.month) &&
		(year == compareTo.year));
    }
    bool operator!=(const Date& compareTo) {
	return !(this->operator==(compareTo));
    }
};

int main() {
    Date holiday(12, 25, 2016);
    holiday.DisplayDate();

    ++holiday;
    holiday.DisplayDate();

    --holiday;
    holiday.DisplayDate();

    cout << holiday << endl;

    Date NextHoliday(holiday + 6);
    cout << "Next holiday on:";
    NextHoliday.DisplayDate();

    cout << "holiday -= 19 gives: ";
    holiday -= 19;
    holiday.DisplayDate();

    cout << "cast:" << endl;
    cout << static_cast<int>(holiday) << endl;

    unique_ptr<int> smartIntPtr(new int);
    *smartIntPtr = 42;

    cout << "Integer value is: " << *smartIntPtr << endl;

    unique_ptr<Date> smartHoliday(new Date(11, 11, 2015));
    cout << "The new instance of date contains: ";
    smartHoliday->DisplayDate();

    Date holiday1(11, 25, 2016);
    Date holiday2(12, 25, 2016);
    cout << "holiday1 equal to holiday2: ";
    if (holiday1 == holiday2) {
	cout << "holiday1 equals to holiday2" << endl;
    } else {
	cout << "holiday1 not equals to holiday2" << endl;
	}

    return 0;
}
