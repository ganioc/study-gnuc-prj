#ifndef _NAMEDATASET_H_
#define _NAMEDATASET_H_

#include <cstring>
#include <iostream>
using namespace std;

class NameDataSet
{
  public:
    char firstName[128];
    char lastName[128];
    int creditCard;
    int nId;

    NameDataSet(int card, const char *fName, const char *lName) : nId(card)
    {
        cout << "Constructor NameDataSet" << endl;
        this->creditCard = card;
        strcpy(this->firstName, fName);
        strcpy(this->lastName, lName);
    }
    ~NameDataSet()
    {
        cout << "DeConstructor NameDataSet" << endl;
    }
    void print();
    void increase();
    void decrease();
    void printId();

  protected:
    void increaseCredit();
    void decreaseCredit();
};
#endif