#include <iostream>

using namespace std;

class Animal {
   public:
    Animal() { cout << "Animal constructor" << endl; }
    int age;
};
class Mammal : virtual public Animal {};
class Bird : virtual public Animal {};
class Reptile : virtual public Animal {};
class Platypus final : public Mammal, public Bird, public Reptile {
   public:
    Platypus() { cout << "Platypus constructor" << endl; }
};
int main() {
    Platypus duckBilledP;

    duckBilledP.age = 11;
}

