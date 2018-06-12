#pragma once

class NameDataSet
{
  public:
    char firstName[128];
    char lastName[128];
    int creditCard;

    NameDataSet(int card)
    {
        this->creditCard = card;
    }
    void print();
};