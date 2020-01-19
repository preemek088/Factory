

#ifndef INFORMATYKA_PROGRAMOWANIE_SYMULACJA_NODES_HPP
#define INFORMATYKA_PROGRAMOWANIE_SYMULACJA_NODES_HPP


#include <memory>
#include <map>
#include <functional>
#include <utility>
#include <optional>
#include "storage_types.hpp"
#include "types.hpp"
#include "helpers.hpp"

enum class ReceiverType{WORKER, STOREHOUSE};

class IPackageReceiver{
public:
    virtual void receive_package(Package&& p) = 0;
    virtual ElementID get_id() const = 0;
    virtual ReceiverType get_receiver_type() const = 0;

    virtual IPackageStockpile::const_iterator begin() const = 0;
    virtual IPackageStockpile::const_iterator end() const = 0;
    virtual IPackageStockpile::const_iterator cbegin() const  = 0;
    virtual IPackageStockpile::const_iterator cend() const  = 0;
};

class ReceiverPreferences{

public:
    using preferences_t = std::map<IPackageReceiver*, double>;
    using const_iterator = preferences_t::const_iterator;

    explicit ReceiverPreferences(ProbabilityGenerator pg = probability_generator): pg_(std::move(pg)) {};

    void add_receiver(IPackageReceiver* r);
    void remove_receiver(IPackageReceiver* r);
    IPackageReceiver* choose_receiver();
    const preferences_t& get_preferences() const {return this->preferences_map;};

    const_iterator cbegin() const  {return this->preferences_map.cbegin();};
    const_iterator cend() const  {return this->preferences_map.cend();};
    typename preferences_t::iterator begin() { return this->preferences_map.begin();};
    typename preferences_t::iterator end() { return this->preferences_map.end();};
private:
    preferences_t preferences_map;
    ProbabilityGenerator pg_;

    void equalise_probability_to_one();
};

class PackageSender{
public:

    PackageSender() = default;
    PackageSender(PackageSender&&) = default;
    ReceiverPreferences receiver_preferences_;

    std::optional<Package>& get_sending_buffer(){return this->sending_buffer;};
    void send_package();

protected:
    void push_package(Package&& p){this->sending_buffer = std::move(p);}

private:
    std::optional<Package> sending_buffer;
};

class Storehouse: public IPackageReceiver{

public:

    explicit Storehouse(ElementID id, std::unique_ptr<IPackageStockpile> d = std::make_unique<PackageQueue>(PackageQueue(PackageQueueType::FIFO))): id_(id),  d_(std::move(d)) {};
    ElementID  get_id() const override { return this->id_;}
    void receive_package(Package&& p) override {this->d_->push(std::move(p));}
    ReceiverType get_receiver_type() const override {return ReceiverType::STOREHOUSE;}
    IPackageStockpile* get_queue() const { return &(*this->d_);}


    IPackageStockpile::const_iterator begin() const override {return this->d_->begin();};
    IPackageStockpile::const_iterator end() const override {return this->d_->end();};
    IPackageStockpile::const_iterator cbegin() const  override {return this->d_->cbegin();};
    IPackageStockpile::const_iterator cend() const  override {return this->d_->cend();};
private:
    ElementID id_;
    std::unique_ptr<IPackageStockpile> d_;

};

class Worker : public IPackageReceiver, public PackageSender {
public:
    Worker(ElementID id, TimeOffset pd, std::unique_ptr<IPackageQueue> q): id_(id), pd_(pd), q_(std::move(q)) {};
    TimeOffset get_processing_duration() const {return this->pd_;};
    ElementID get_id() const override {return this->id_;};
    void receive_package(Package&& p) override {this->q_->push(std::move(p));};
    void do_work(Time t);
    Time get_package_processing_start_time() const {return this->st_;};
    ReceiverType get_receiver_type() const override {return ReceiverType::WORKER;}
    IPackageQueue* get_queue() const { return &(*this->q_);}
    bool is_processing() const;
    ElementID get_processed_id() const { return this->work_buffor->get_id();}

    IPackageStockpile::const_iterator begin() const override {return this->q_->begin();};
    IPackageStockpile::const_iterator end() const override {return this->q_->end();};
    IPackageStockpile::const_iterator cbegin() const  override {return this->q_->cbegin();};
    IPackageStockpile::const_iterator cend() const  override {return this->q_->cend();};
private:
    ElementID id_;
    TimeOffset pd_;
    Time st_ = 0;
    std::unique_ptr<IPackageQueue> q_;
    std::optional<Package> work_buffor;
};

class Ramp : public PackageSender {
public:
    Ramp(ElementID id, TimeOffset di): id_(id), di_(di) {};
    TimeOffset get_delivery_interval() const { return this->di_;};
    ElementID get_id() const {return this->id_;};
    void deliver_goods(Time t);

private:
    ElementID id_;
    TimeOffset di_;

};

#endif //INFORMATYKA_PROGRAMOWANIE_SYMULACJA_NODES_HPP
