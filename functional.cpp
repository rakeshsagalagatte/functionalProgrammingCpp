#include<iostream>
#include<functional>
#include<vector>
#include<string>

using namespace std;
void demoFunction(){
    cout << "Demo Function called" << endl;
}

void adder(int a, int b){
    cout << "a + b = " << a+b << endl;
}

class functor{
    public:
        void operator()() const {
            cout << "Called functor" << endl;
        }
};


int main(){
    vector<function<void()>> funcs;           // list of function 
    funcs.push_back(demoFunction);
    
    functor functor_instance;
    funcs.push_back(functor_instance); 
    funcs.push_back([](){ cout << "Called anonymous lambda " << endl; });   //lambda function 
    funcs.push_back(std::bind(&adder, 10, 15));

    for(auto &f: funcs){
        f();
    }
    return 0;
}