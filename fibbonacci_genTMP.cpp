#include<iostream>
using namespace std;

template<int n>
struct Fibbonacci {
    enum{
        value = Fibbonacci<n-1>::value + Fibbonacci<n-2>::value
    };
};

template<>
struct Fibbonacci<0>{
    enum{
        value = 0
    };
};

template<>
struct Fibbonacci<1>{
    enum{
        value = 1
    };
};

int main(){
    //render code
    cout << "Fib(0) = " << Fibbonacci<0>::value << endl;
    cout << "Fib<1>  = " << Fibbonacci<1>::value << endl;
    cout << "Fib<2>  = " << Fibbonacci<2>::value << endl;
    cout << "Fib<3>  = " << Fibbonacci<3>::value << endl;
    cout << "Fib<4>  = " << Fibbonacci<4>::value << endl;
    cout << "Fib<12> = " << Fibbonacci<12>::value << endl;
    cout << "Fib<13> = " << Fibbonacci<13>::value << endl;
    cout << "Fib<14> = " << Fibbonacci<14>::value << endl;
    return 0;
}