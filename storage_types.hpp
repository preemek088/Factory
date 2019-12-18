//#ifndef FACTORY_STORAGE_TYPES_HPP
//#define FACTORY_STORAGE_TYPES_HPP
//
//#include <list>
//#include "package.hpp"
//
//enum class PackageQueueType
//{
//    LIFO, FIFO
//};
//
//class IPackageStockPile
//{
//    virtual void push(Package&& Package) = 0;
//    virtual bool empty() = 0;
//    virtual int size() = 0;
//
//};
//
//class IPackageQueue: public IPackageStockPile
//{
//    virtual void pop() = 0;
//    virtual PackageQueueType get_queue_type() = 0;
//
//};
//
//class PackageQueue: public IPackageQueue
//{
//    std::list<Package> products;
//    PackageQueueType queue_type;
//
//    PackageQueue(PackageQueueType type);
//    void pop() override;
//
//};
//
//
//#endif //FACTORY_STORAGE_TYPES_HPP
