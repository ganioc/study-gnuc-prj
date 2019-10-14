#include <string.h>
#include <iostream>

using namespace std;

class President {
   private:
    President(){};
    President(const President&);
    const President& operator=(const President&);
    string name;

   public:
    static President& GetInstance() {
	static President onlyInstance;
	return onlyInstance;
    }
    string GetName() { return name; }
    void SetName(string InputName) { name = InputName; }
};
