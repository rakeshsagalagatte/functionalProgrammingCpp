#include<iostream>

using namespace std;

auto incrementor = []() {
    int increment =0;
    return [increment]() mutable {     // reason to use mutable : Any time we want to modify a value that's in the closure,
        return increment++;             //  We have to say mutable.
    };
};
int main(){

    auto myInc = incrementor();
    cout << "myInc = " << myInc() << endl;
    cout << "myInc = " << myInc() << endl;
    cout << "myInc = " << myInc() << endl;
    cout << "myInc = " << myInc() << endl;
    cout << "myInc = " << myInc() << endl;
    cout << "myInc = " << myInc() << endl;
    return 0;
}