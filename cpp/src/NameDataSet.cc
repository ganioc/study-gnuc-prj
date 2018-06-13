#include "NameDataSet.h"
#include <iostream>
using namespace std;

void NameDataSet::print()
{
    cout << "Hi credit card is: " << this->creditCard << endl;
    cout << "Mr. " << this->firstName << " " << this->lastName << endl;
}
void NameDataSet::increase()
{
    this->increaseCredit();
}
void NameDataSet::decrease()
{
    this->decreaseCredit();
}
void NameDataSet::printId()
{
    cout << this->nId << endl;
}
// protected
void NameDataSet::increaseCredit()
{
    this->creditCard++;
}
void NameDataSet::decreaseCredit()
{
    this->creditCard--;
}
