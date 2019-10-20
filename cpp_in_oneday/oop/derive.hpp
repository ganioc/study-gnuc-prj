#include <iostream>
using namespace std;

class Fish {
protected:
   bool isFreshWaterFish;

public:
 Fish(bool isFreshWater) : isFreshWaterFish(isFreshWater) {}
 ~Fish() { cout << "Fish destructor" << endl; }
 void Swim() {
     if (isFreshWaterFish)
	 cout << "Swims in lake" << endl;
     else
	 cout << "Swims in sea" << endl;
  }
};
class Carp : public Fish {
   public:
    Carp() : Fish(false) {}
	~Carp(){
		cout << "Carp destructor" << endl;
	}
    void Swim() {
	cout << "Carp swims really slow" << endl;
	Fish::Swim();
    }
};

class Tuna : public Fish {
   public:
    Tuna() : Fish(true) {}
	~Tuna(){
		cout << "Tuna destructor" << endl;
	}
    void Swim() { cout << "Tuna Swims really fast" << endl;
		Fish::Swim();   
	}
};
