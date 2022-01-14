#include <iostream>
#include <string>
#include <map>
#include <cctype>
#include <sstream>

#include "calculator.h"
#include "TokenStream.h"

using namespace std;

int no_of_errors;
TokenStream ts{cin};
// a symbol table
map<string, double> table;

double error(const string& s){
    no_of_errors++;
    cerr << "error: " << s << "\n";
    return 1;
}
// 处理基本值, 也就是, 获取一个基本值，也有可能是(xxx), 带括号的,
double prim(bool get){
    if(get) 
        ts.get(); // read the next token
    
    switch(ts.current().kind){
        case Kind::number: // floating point constant
        {
            double v = ts.current().number_value;
            ts.get();
            return v;
        }
        case Kind::name:
        {
            // symbol table is queried!
            double& v = table[ts.current().string_value];// find the corresponding
            if(ts.get().kind == Kind::assign)
                v = expr(true); // = seen: assignment
            return v;
        }
        case Kind::minus:
            return -prim(true);
        case Kind::lp:
        {
            auto e = expr(true);
            if(ts.current().kind != Kind::rp)
                return error("')' expected");
            ts.get(); // eat ')', ????
            return e;
        }
        default:
            return error("primary expected");
    }
}
// 处理 multiply and division, divide, 
double term(bool get){
    double left = prim(get);
    for(;;){
        switch(ts.current().kind){
            case Kind::mul:
                left *= prim(true);
                break;
            case Kind::div:
                if(auto d =  prim(true)){
                    left /= d;
                    break;
                }
                return error("divided by 0");
            default:
                return left;
        }
    }
}
// bool,
// Whether needs to call Token_stream::get() to get the next
// token,处理addition, and subtraction, 
double expr(bool get){
    double left=term(get);
    for(;;){
        switch(ts.current().kind){
            case Kind::plus:
                left+= term(true);
                break;
            case Kind::minus:
                left-= term(true);
                break;
            default:
                return left;
        }
    }
}

void calculate(){
    for(;;){
        ts.get();
        if(ts.current().kind == Kind::end)
            break;
        
        if(ts.current().kind == Kind::print)
            continue;

        cout << expr(false) << '\n';
    }
}

void test_expr(){
    constexpr int x2=0;

    constexpr int x3=x2;

    cout << "test_expr()" << endl;
    cout << x3 << endl;

}
int main(int argc, char* argv[]){
    cout << "Hello, calculator()" << endl;

    switch(argc){
        case 1:
            break;
        case 2:
            ts.set_input(new istringstream{argv[1]});
            break;
        default:
            error("too many arguments");
            return 1;
    }

    table["pi"] = 3.14159265357932385;
    table["e"] = 2.7182818284590452354;

    calculate();

    cout << "End of main" << endl;

    test_expr();
    return 0;
}

