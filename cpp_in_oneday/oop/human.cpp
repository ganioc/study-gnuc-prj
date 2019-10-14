#include "human.h"

void Human::IntroduceSelf() {
  cout << "Human attr:" << endl;
  cout << "\tbirth date: " << this->dateOfBirth << endl;
  cout << "\tage: " << this->age << endl;
}
int Human::GetAge() { return this->age; }

void Human::SetAge(int humanAge) { this->age = humanAge; }
