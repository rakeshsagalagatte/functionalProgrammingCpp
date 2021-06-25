#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>

using namespace std;

int main(){
    auto render = [](auto collection){
        for(const auto &val: collection){
            cout << val << endl;                         // Lambda function
        }
    };

    // Transform 
    vector<int> inCollection{1,2,3,4,5,6,7,8,9,10};
    vector<int> outCollection;
    transform(inCollection.begin(), inCollection.end(), 
            back_inserter(outCollection), [](const int &value){ return value * 3; }
    );

    cout << "Transform " << endl;
    render(outCollection);

    // Copy IF
    vector<int> filteredCollection;
    copy_if(outCollection.begin(), outCollection.end(),
            back_inserter(filteredCollection), [](const int &value){ return value%2 != 0; }
    );
    cout << "Copy IF " << endl;
    render(filteredCollection);

    //  Accumulate 

    int results = accumulate(filteredCollection.begin(), filteredCollection.end(),
        0, [](int total, int current){ return total + current ;}
    );
    cout << "Accumulate" << endl;
    cout << "results: " << results << endl;
    return 0;
}