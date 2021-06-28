#include "./RxCpp/Rx/v2/src/rxcpp/rx.hpp"

namespace Rx {
    using namespace rxcpp;
    using namespace rxcpp::sources;
    using namespace rxcpp::operators;
    using namespace rxcpp::util;
}
using namespace Rx;

#include <iostream>

int main(){
    std::vector<int> ages{9, 20, 13, 4 ,5, 6, 10, 28, 19, 15, 60, 10, 23 , 47, 12, 19, 99};
    auto values = rxcpp::observable<>::iterate(ages).
        filter([](int age){ return ((age >=13)&& (age <= 19)); }).
        subscribe(
            [](int age){ std::cout << age << std::endl; },
            [](){ std::cout << "On Completed " << std::endl; }
        );
    return 0;
}

