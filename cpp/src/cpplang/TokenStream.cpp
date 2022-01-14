#include "TokenStream.h"

Token TokenStream::get(){
    // read a character, to decide what kind of token needs to be composed
    // read more characters when needed, 
    // return a Token 
    char ch = 0;
    // *ip >> ch; // skips white space, tabs, newlines

    do {
        // skip whitespace except '\n'
        // reads a single character from input stream into ch
        if(!ip->get(ch))
            return ct={Kind::end};
    } while(ch!='\n' && isspace(ch));

    switch(ch){
        case 0:
            return ct={Kind::end};
        case ';':
        case '\n':
            return ct={Kind::print};
        case '*':
        case '/':
        case '+':
        case '-':
        case '(':
        case ')':
        case '=':
            return ct={static_cast<Kind>(ch)};
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case '.':
            ip->putback(ch); // put the first digit or . back into the input stream
            *ip >> ct.number_value; // read the number into ct
            ct.kind = Kind::number;
            return ct;
        default: // name, name=, or error
            if(isalpha(ch)){
                // ip->putback(ch); // put the 1st character back into the input stream
                // *ip >> ct.string_value;
                // ct.kind = Kind::name;
                // return ct;


                // string_value;
                ct.string_value.push_back(ch);
                while(ip->get(ch)&& isalnum(ch))
                    ct.string_value += ch; // append ch to end of string_value
                ip->putback(ch);
                ct.kind = Kind::name;
                return ct; // ={Kind::name};
            }
            error("bad token");
            return ct={Kind::print};
    }
}