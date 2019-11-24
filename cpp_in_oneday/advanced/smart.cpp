#include <iostream>
#include <memory>

using namespace std;

template <typename T>
class destructivecopy_ptr {
private:
    T* object;

public:
    destructivecopy_ptr(T* input) : object(input) {}
    ~destructivecopy_ptr() { delete object; }

    destructivecopy_ptr(destructivecopy_ptr& source) {
	object = source.object;
	source.object = 0;
    }
    // copy assignment operator
    destructivecopy_ptr& operator=(destructivecopy_ptr& source) {
	if (object != source.object) {
	    delete object;
	    object = source.object;
	    source.object = 0;
	}
  }
};

class Fish {
public:
    Fish() { cout << "Fish: Constructed!" << endl; }
    ~Fish() { cout << "Fish: Destructed!" << endl; }

    void Swim() const { cout << "Fish swims in water" << endl; }
};

void MakeFishSwim(const unique_ptr<Fish>& inFish) { inFish->Swim(); }
int main() {
    destructivecopy_ptr<int> num(new int);
    destructivecopy_ptr<int> copy = num;

    unique_ptr<Fish> smartFish(new Fish);
    smartFish->Swim();
    MakeFishSwim(smartFish);

    unique_ptr<Fish> copySmartFish;
    // copySmartFish = smartFish;
    unique_ptr<Fish> sameFish(std::move(smartFish));

    unique_ptr<char> alphabet(new char);
    *alphabet = 's';
    auto lambda = [capture = move(alphabet)]() {
	cout << *capture << endl;
    };
    lambda();

    return 0;}

