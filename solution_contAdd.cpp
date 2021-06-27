#include<iostream>

using namespace std;

auto contineousAdd = [](int initial, int addBy) {
    int total = initial;
    return [total, addBy]() mutable {
        total += addBy;
        return total;
    };
};

int main(){
    auto x = contineousAdd(1000, 20);
    cout << x() << endl;
    cout << x() << endl;
    cout << x() << endl;
    cout << x() << endl;
    cout << x() << endl;
    cout << x() << endl;
    cout << x() << endl;
    cout << x() << endl;
    return 0;
}