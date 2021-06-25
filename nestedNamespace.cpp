#include<iostream>

namespace A::B::C {
    int i;
}

int main(){
    A::B::C::i = 49;
    std::cout << "Nested namespace are available: " << A::B::C::i << std::endl;
    return 0;
}