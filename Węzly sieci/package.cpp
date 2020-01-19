//
// Created by Kacper on 19/01/2020.
//

#include "package.hpp"

Package::Package() {
    if(not freed_IDs.empty()){
        this->ID = *(freed_IDs.begin()); //Wybieram największe nieużyte ID i używam go
        assigned_IDs.insert(*(freed_IDs.begin()));
        freed_IDs.erase(*(freed_IDs.begin()));
    }
    else{
        if(assigned_IDs.empty()){
            this->ID = 1;
            assigned_IDs.insert(1);
        }
        else{
            this->ID = *(assigned_IDs.rbegin()) + 1; //Biorę ID większe niż największe użyte
            assigned_IDs.insert(*(assigned_IDs.rbegin()) + 1);
        }
    }
}

 Package::~Package() {
    freed_IDs.insert(this->ID);
    assigned_IDs.erase(this->ID);
}
