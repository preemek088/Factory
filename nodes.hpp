

#ifndef FACTORY_NODES_HPP
#define FACTORY_NODES_HPP

#include "package.hpp"
#include <memory>
#include "storage_types.hpp"
#include <vector>
class IPackageReceiver
{
    void receive_package(Package&& p) {};
    virtual ElementID get_id() = 0;


};

class Storehouse
{
    Storehouse(ElementID ID, std::unique_ptr<IPackageStockPile> d) {};

};

class ReceiverPreferences
{
    void add_receiver(IPackageReceiver* r) {};
    void remove_receiver(IPackageReceiver* r) {};
    IPackageReceiver* choose_receiver() {};

};

class PackageSender
{
    ReceiverPreferences receiver_preferences_;
    void send_package() {};
    virtual std::vector<Package> get_sending_buffer() = 0;
    void push_package(Package&& p) {};

};

class Ramp
{
    Ramp(ElementID ID, TimeOffset DI) {};
    void deliver_goods(Time t) {};
    virtual TimeOffset get_delivery_interval() = 0;
    ElementID get_id() {};
};

class Worker
{
    Worker(ElementID ID, TimeOffset pd, std::unique_ptr<PackageQueue> q) {};
    void do_work(Time t) {};
    TimeOffset get_processing_duration() {};
    Time get_package_processing_start_time() {};




};


#endif //FACTORY_NODES_HPP
