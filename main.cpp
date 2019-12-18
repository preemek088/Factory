#include <iostream>
#include <deque>
#include "package.hpp"
#include "storage_types.hpp"

using elementID = int;

int main() {

    Package paczka;
    Package paczka2;
    std::cout<<paczka.get_id();
    std::cout<<"\n"<<paczka2.get_id();

    return 0;
}