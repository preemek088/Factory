#ifndef FACTORY_STORAGE_TYPES_HPP
#define FACTORY_STORAGE_TYPES_HPP

#include "package.hpp"

enum PackageQueueType
{
    LIFO, FIFO
};

class IPackageStockPile
{
    virtual void push(Package&& Package) = 0;
    virtual bool empty() = 0;
    virtual int size() {};


};

class IPackageQueue
{
    virtual void pop() = 0;
    virtual PackageQueueType get_queue_type() = 0;

};

class PackageQueue: public IPackageQueue
{



};


#endif //FACTORY_STORAGE_TYPES_HPP
