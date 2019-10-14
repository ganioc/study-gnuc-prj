#include <iostream>

using namespace std;

class Human {
    //
   private:
    string name;
    string placeOfBirth;
    string gender;
    int age;

   public:
    string dateOfBirth;
    // function
    Human() { this->age = 0;
	this->dateOfBirth = "1900";
	}
	~Human(){}
    void Talk(string textToTalk);
    void IntroduceSelf();
    int GetAge();
    void SetAge(int humanAge);
};

