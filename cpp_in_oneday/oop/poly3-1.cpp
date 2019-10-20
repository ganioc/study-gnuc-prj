#include <iostream>
using namespace std;

class Fish {
   public:
    virtual void Swim() = 0;
    virtual Fish* Clone() = 0;
};
class Tuna : public Fish {
   public:
    void Swim() override { cout << "Tuna swims!" << endl; }
    Fish* Clone() override { return new Tuna(*this); }
};
class BluefinTuna final : public Tuna {
   public:
    Fish* Clone() override { return new BluefinTuna(*this); }
};
class Carp final : public Fish {
    void Swim() override final { cout << "Carp swims!" << endl; }
    Fish* Clone() override { return new Carp(*this); }
};

void MakeFishSwim(Fish& inputFish) { inputFish.Swim(); }

int main() {
    cout << "Polymorph" << endl;
    Tuna myDinner;
    Carp myLunch;

    myDinner.Swim();

    MakeFishSwim(myDinner);
    MakeFishSwim(myLunch);
    cout << "---------------" << endl;
    const int ARRY_SIZE = 4;
    Fish* myFished[ARRY_SIZE] = {NULL};
    myFished[0] = new Tuna();
    myFished[1] = new Carp();
    myFished[2] = new BluefinTuna();
    myFished[3] = new Carp();

    Fish* myNewFishes[ARRY_SIZE];
    for (int index = 0; index < ARRY_SIZE; ++index) {
	myNewFishes[index] = myFished[index]->Clone();
    }

    for (int index = 0; index < ARRY_SIZE; ++index) {
	myNewFishes[index]->Swim();
    }

    for (int index = 0; index < ARRY_SIZE; ++index) {
	delete myFished[index];
	delete myNewFishes[index];
    }

    return 0;
}
