#include <iostream>
using namespace std;

class Fish {
   public:
    Fish() { cout << "Constructor Fish" << endl; }
    virtual ~Fish() { cout << "Destroyed Fish" << endl; }
    void Swim() { cout << "Fish swims!" << endl; }
};
class Tuna : public Fish {
   public:
    Tuna() { cout << "Constructor Tuna" << endl; }
    ~Tuna() { cout << "Destroyed Tuna" << endl; }
    void Swim() { cout << "Tuna swims!" << endl; }
};
void DeleteFishMemory(Fish* pFish) { delete pFish; }
void MakeFishSwim(Fish& inputFish) { inputFish.Swim(); }

int main() {
    cout << "Polymorph" << endl;
    Tuna myDinner;

    myDinner.Swim();

    MakeFishSwim(myDinner);
    cout << "-----------------" << endl;

    Tuna* pTuna = new Tuna;
    cout << "deleting the Tuna: " << endl;
    DeleteFishMemory(pTuna);
    cout << "Instantiating a Tuna on the stack" << endl;
    Tuna my2ndTuna;
    cout << "Automatic destruction as it goes out of scope:" << endl;

    return 0;
}
