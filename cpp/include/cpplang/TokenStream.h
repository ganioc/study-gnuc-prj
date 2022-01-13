#pragma once
#include <iostream>
#include "calculator.h"

class TokenStream{
    public:
        TokenStream(istream& s):ip{&s}, owns{false} {}
        TokenStream(istream* p):ip{p}, owns{true}{}
        ~TokenStream(){close();}

        Token get(); // read and return next token
        const Token& current(){ return ct; } // most recently read token

        void set_input(istream& s){
            close();
            ip=&s;
            owns=false;
        }
        void set_input(istream* p){
            close();
            ip=p;
            owns=true;
        }
    private:
        void close(){ if(owns) delete ip; }

        istream *ip; // pointer to an input stream
        bool owns;   // does the TokenStream own the istream?
        Token ct {Kind::end}; // current token

};
