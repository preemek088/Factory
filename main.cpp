#include <iostream>
#include <deque>
#include <vector>
#include <set>
#include <iterator>
using elementID = int;


class Package
{
    elementID ID;
    static std::set<elementID> assigned_IDs;
    static std::set<elementID> freed_IDs;
public:
    Package(elementID ID_) //konstruktor
    {
        ID = ID_;
    };
    Package(Package&& arg): ID(std::move(arg.ID)) //konstruktor kopiujacy
    {}
    Package& operator=(Package&& other)
    {
        ID = std::move(other.ID);
        return *this;
    };
    ~Package(); //destruktor domyslny, tutaj przy zniszczeniu obiektu powinno przekazywac ID produktu do zbioru zwolnionych ID
    elementID get_id() const
    {
        return ID;
    }

};

enum PackageQueueType
{
    LIFO, FIFO

};

class IPackageStockPile
{
protected: //protected daje dostep klasie pochodnej do wszystkich pol, ale nie daje dostepu z zewnatrz(spoza klasy)
    virtual void push(Package&& Package) = 0;
    virtual bool empty() = 0;
    virtual std::size_t size() {return 1;};
    ~IPackageStockPile() {};

};

class IPackageQueue
{
protected:
    virtual void pop() = 0;
    virtual PackageQueueType get_queue_type() = 0;
    ~IPackageQueue() {};
};

class PackageQueue: public IPackageQueue
{
    std::deque<Package> queue;
public:
    void push(Package&& package) {queue.push_back(package);};

    bool empty() {return (queue.size()==0);};

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