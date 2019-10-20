#include <iostream>
using namespace std;

class Fish {
   public:
    virtual void Swim()
    = 0;
};
class Tuna : public Fish {
   public:
    void Swim() { cout << "Tuna swims!" << endl; }
};

class Carp : public Fish {
    void Swim() { cout << "Carp swims!" << endl; }
};

void MakeFishSwim(Fish& inputFish) { inputFish.Swim(); }

int main() {
    cout << "Polymorph" << endl;
    Tuna myDinner;
    Carp myLunch;

    myDinner.Swim();
    cout << "Make fish swim:" << endl;
    MakeFishSwim(myDinner);
    MakeFishSwim(myLunch);

    return 0;
}
