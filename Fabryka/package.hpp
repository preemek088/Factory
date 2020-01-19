//
// Created by Kacper on 19/01/2020.
//

#ifndef INFORMATYKA_PROGRAMOWANIE_SYMULACJA_PACKAGE_HPP
#define INFORMATYKA_PROGRAMOWANIE_SYMULACJA_PACKAGE_HPP

#include <set>
#include "types.hpp"

static std::set<ElementID> assigned_IDs;
static std::set<ElementID> freed_IDs;

class Package{

public:

    Package();
    explicit  Package(ElementID id): ID(id) {};
    Package(Package&&) = default;
    Package& operator=(Package&&) = default;
    ElementID get_id() const {return this->ID;}
    ~Package();
private:
    ElementID ID;

};

#endif //INFORMATYKA_PROGRAMOWANIE_SYMULACJA_PACKAGE_HPP
