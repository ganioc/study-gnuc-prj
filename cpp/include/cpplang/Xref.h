#pragma once

template<typename T>
class Xref{
    public:
    Xref(int i, T* p): index{i},elem{p},owned{true}{

    }
    Xref(int i, T&r):index{i}, elem{&r}, owned{false} {

    }
    Xref(int i, T&& r):index{i}, elem{new T{move(r)}},owned{true}{

    } // Xref<string> r1 {1, "here"} right string, rvalue,
    ~Xref(){
        if(owned) delete elem;
    }
    private:
    int index;
    T* elem;
    bool owned;
};

// template<typename T>
// T max(T,T);
// (T a,T b){
//     if(a < b){
//         return b;
//     }else{
//         return a;
//     }
// }

