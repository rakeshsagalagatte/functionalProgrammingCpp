#include<iostream>

using namespace std;

auto addCurry = [](auto a){
    return [a](auto b){
        return [a, b](auto c){
            return a+b+c;
        };
    };                               // reason to sq. brackets is if we want to access outer varible then specify it.
};                             /*
                                    At each level we have a varible out of scope that we want to capture, 
                                    wrap a closure arround , included in the capture list.
                             */
int main(){
    auto added1 = addCurry(1);  // It gives back another i.e, 2th inner function
    auto added2 = added1(10);  //It gives 3rd inner function
    auto addResults = added2(100);
    cout << "Results : " << addResults << endl;
    auto allAtOnce = addCurry(990000)(9900)(99);
    cout << "allAtOne : " << allAtOnce << endl;

    return 0;
}