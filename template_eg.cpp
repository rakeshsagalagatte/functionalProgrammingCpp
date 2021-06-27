#include<iostream>

using namespace std;

template<typename T>                     // This template function going to get create during runtime time. 
T cube(const T& value){                    // T is a generic type
    return value * value * value;
}                                      

template<int toCube>
struct Cube{
    enum{
        value = toCube * toCube * toCube
    };
};

int main(){
    cout << "8 cubed = " << cube(8) << endl;
    cout << "5 Cubed = " << Cube<5>::value << endl;
    return 0;
}

