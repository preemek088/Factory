#include <set>
#include "package.hpp"

std::set<elementID> Package::freed_IDs;
std::set<elementID> Package::assigned_IDs;

elementID Package::get_id() const {
    return ID;
}
