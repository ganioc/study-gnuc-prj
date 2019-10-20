#include <iostream>
using namespace std;

class Fish {
   public:
    void Swim() { cout << "Fish swims!" << endl; }
};
class Tuna : public Fish {
   public:
    void Swim() { cout << "Tuna swims!" << endl; }
};
void MakeFishSwim(Fish& inputFish) { inputFish.Swim(); }

int main() {
    cout << "Polymorph" << endl;
    Tuna myDinner;

    myDinner.Swim();

    MakeFishSwim(myDinner);

    return 0;
}
