#ifndef FACTORY_PACKAGE_HPP
#define FACTORY_PACKAGE_HPP

#include <iostream>
#include "types.hpp"
#include <deque>
#include <set>
#include <stdexcept>

class Package {
public:
    Package();

    explicit Package(ElementID id);

    Package(const Package&) = delete;
    Package(Package&&) noexcept;

    Package& operator=(Package&) = delete;
    Package& operator=(Package&&) noexcept;

    ~Package();

    ElementID get_id() const { return id_; }

private:
    static const ElementID BLANK_ID = -1;

    inline static std::set<ElementID> assigned_ids_{0};

    inline static std::set<ElementID> freed_ids_;

    ElementID id_ = BLANK_ID;
};

#endif FACTORY_PACKAGE_HPP
