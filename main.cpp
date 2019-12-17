#include <iostream>
#include <deque>
using elementID = int;

class Package
{
    elementID ID;
public:
    Package(elementID ID_) {
        ID = ID_;
    };
    ~Package() = default;
    elementID get_id() const {
        return ID;
    }

};

enum PackageQueueType
{
    LIFO, FIFO

};

class IPackageStockPile
{
    virtual void push(Package&& Package) = 0;
    virtual bool empty() = 0;
    virtual std::size_t size() {};


};

class IPackageQueue
{
    virtual void pop() = 0;
    virtual PackageQueueType get_queue_type() = 0;

};

class PackageQueue: public IPackageQueue
{
    std::deque<Package> queue;
public:
    void push(Package&& package) {queue.push_back(package);};

    bool empty() {if (queue.size()>0) return true;};

    std::size_t size() const {return queue.size();};

    // typ FIFO
    void pop() {queue.pop_front();};
    PackageQueueType get_queue_type() {return LIFO;};
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << "tu byl kacper i udalo mu sie skonfigurowac cliona" <<std::endl;
    std::cout <<"tu byl kacper i teraz juz mu sie naprawde udalo skonfigurowac cliona"<<std::endl;
    Package paczka(2);
    std::cout<<paczka.get_id();
    return 0;
}