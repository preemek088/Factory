//
// Created by Kacper on 19/01/2020.
//

#ifndef INFORMATYKA_PROGRAMOWANIE_SYMULACJA_STORAGE_TYPES_HPP
#define INFORMATYKA_PROGRAMOWANIE_SYMULACJA_STORAGE_TYPES_HPP


#include "package.hpp"
#include <list>
#include "types.hpp"

enum class PackageQueueType{FIFO, LIFO};

class IPackageStockpile{
public:
    virtual void push(Package&& package) = 0;
    virtual bool empty() const = 0;
    virtual  int size() const = 0;

    using const_iterator = std::list<Package>::const_iterator;

    virtual const_iterator begin() const  = 0;
    virtual const_iterator end() const  = 0;
    virtual const_iterator cbegin() const = 0;
    virtual const_iterator cend() const  = 0;


};

class IPackageQueue : public IPackageStockpile{
public:
    virtual Package pop() = 0;
    virtual PackageQueueType get_queue_type() const = 0;
};

class PackageQueue : public IPackageQueue{

public:
    explicit PackageQueue(PackageQueueType type) : queue_type(type){};
    PackageQueueType get_queue_type() const override {return this->queue_type;}
    Package pop();
    bool empty() const override {return this->queue.empty();}
    int size() const override {return this->queue.size();}
    void push(Package&& package) override { this->queue.emplace_back(std::move(package));}

    IPackageStockpile::const_iterator begin() const override { return this->queue.begin();}
    IPackageStockpile::const_iterator end() const override { return this->queue.end();}
    IPackageStockpile::const_iterator cbegin() const  override { return this->queue.cbegin();}
    IPackageStockpile::const_iterator cend() const  override { return this->queue.cend();}

private:
    PackageQueueType queue_type;
    std::list<Package> queue;
};

#endif //INFORMATYKA_PROGRAMOWANIE_SYMULACJA_STORAGE_TYPES_HPP
