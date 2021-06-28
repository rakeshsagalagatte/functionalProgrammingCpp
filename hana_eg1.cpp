#include<iostream>
#include<string>
#include<boost/hana.hpp>
namespace hana = boost::hana;

using namespace hana::literals;
using namespace std;

struct Truck {
    std::string name;
    double bed_length;
};

struct Car {
    std::string name;
};

struct Motorcycle {
    std::string name;
};

int main(){
    auto vehicals = hana::make_tuple(
        Truck{"F-150", 8.5}, Car{"Volt"}, Motorcycle{"Ninja"}       // Heterogenous fuction 
    );
    auto has_bed_length = hana::is_valid(
        [](auto &&x)-> decltype((void) x.bed_length){}
    );
    auto trucks = hana::filter(vehicals, has_bed_length);   // filter accourding to wheather member having bed_length or not
    auto non_trucks = hana::filter(vehicals, hana::compose(hana::not_, has_bed_length));    // compose takes >2 fucntions and makes them one function
                                                                    //  haana::not_ performs not gate

    //rendring code
    hana::for_each(trucks, [](auto &vehical){
        cout << "Trucks = " << vehical.name << ", bed length = " << vehical.bed_length << endl;
    });
    hana::for_each(non_trucks, [](auto &vehical){
        cout << "Non trucks = " << vehical.name << endl;
    });
    return 0;
}