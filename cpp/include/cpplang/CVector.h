#pragma once

class CVector{
    public:
        CVector(int s): elem{ new double[s]}, sz{s}{

        }
        
        ~CVector(){ delete[] elem;}
        double & operator[](int i){
            return elem[i];
        }
        int size() { return sz; }
        void push_back(double);
    private:
        double *elem;
        int sz;
};
