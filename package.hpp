#ifndef FACTORY_PACKAGE_HPP
#define FACTORY_PACKAGE_HPP

#include <iostream>
#include "types.hpp"
#include <deque>
#include <set>

class Package
{
    elementID ID;
    static std::set<elementID> assigned_IDs;
    static std::set<elementID> freed_IDs;

public:
    Package& operator = (Package&&) = default;
    Package() {
        elementID x = 1;
        while(true){
            const bool is_in_assigned = assigned_IDs.find(x) != assigned_IDs.end();
            const bool is_in_freed = freed_IDs.find(x) != freed_IDs.end();
            if(is_in_freed){
                ID = x;
                assigned_IDs.emplace(ID);
                break;
            }
            if(is_in_assigned == 0){
                ID = x;
                assigned_IDs.emplace(ID);
                break;
            }
            if(is_in_assigned){
                if(x == *assigned_IDs.end()){
                    x=*assigned_IDs.end()+1;
                    ID = x;
                    assigned_IDs.emplace(ID);
                    break;
                }
            }
            x++;
        }
    }
    ~Package(){
        assigned_IDs.erase(ID);
        freed_IDs.emplace(ID);
    };
    elementID get_id() const;

};

#endif //FACTORY_PACKAGE_HPP
