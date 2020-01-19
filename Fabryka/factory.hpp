

#ifndef INFORMATYKA_PROGRAMOWANIE_SYMULACJA_FACTORY_HPP
#define INFORMATYKA_PROGRAMOWANIE_SYMULACJA_FACTORY_HPP

#include <list>
#include "types.hpp"
#include "nodes.hpp"

template <typename Node>
class NodeCollection{
public:

    using container_t = typename std::list<Node>;
    using iterator = typename container_t::iterator;
    using const_iterator = typename container_t::const_iterator;


    iterator begin(){return this->container_.begin();}
    iterator end(){return this->container_.end();}
    const_iterator cbegin() const {return this->container_.cbegin();}
    const_iterator cend() const {return this->container_.cend();}

    void add(Node&& node){this->container_.emplace_back(std::move(node));}
    iterator find_by_id(ElementID id){return std::find_if(this->begin(), this->end(), [&](auto& elem){return elem.get_id() == id;});};
    const_iterator find_by_id(ElementID id) const {return std::find_if(this->cbegin(), this->cend(), [&](const auto& elem){return elem.get_id() == id;});};
    void remove_by_id(ElementID id){this->container_.erase(this->find_by_id(id));}

private:
    container_t container_;
};

class Factory{
public:

// Ramp
    void add_ramp(Ramp&& ramp){this->ramp_collection.add(std::move(ramp));}
    void remove_ramp(ElementID id){this->ramp_collection.remove_by_id(id);}
    NodeCollection<Ramp>::iterator find_ramp_by_id(ElementID id){return this->ramp_collection.find_by_id(id);}
    NodeCollection<Ramp>::const_iterator find_ramp_by_id(ElementID id) const {return this->ramp_collection.find_by_id(id);}
    NodeCollection<Ramp>::const_iterator ramp_cbegin() const { return this->ramp_collection.cbegin();}
    NodeCollection<Ramp>::const_iterator ramp_cend() const { return this->ramp_collection.cend();}

// Worker
    void add_worker(Worker&& worker){this->worker_collection.add(std::move(worker));}
    void remove_worker(ElementID id){this->remove_receiver(this->worker_collection, id);}
    NodeCollection<Worker>::iterator find_worker_by_id(ElementID id){return this->worker_collection.find_by_id(id);}
    NodeCollection<Worker>::const_iterator find_worker_by_id(ElementID id) const {return this->worker_collection.find_by_id(id);}
    NodeCollection<Worker>::const_iterator worker_cbegin() const { return this->worker_collection.cbegin();}
    NodeCollection<Worker>::const_iterator worker_cend() const { return this->worker_collection.cend();}

// Storehouse
    void add_storehouse(Storehouse&& storehouse){this->storehouse_collection.add(std::move(storehouse));}
    void remove_storehouse(ElementID id){this->remove_receiver(this->storehouse_collection, id);}
    NodeCollection<Storehouse>::iterator find_storehouse_by_id(ElementID id){return this->storehouse_collection.find_by_id(id);}
    NodeCollection<Storehouse>::const_iterator find_storehouse_by_id(ElementID id) const {return this->storehouse_collection.find_by_id(id);}
    NodeCollection<Storehouse>::const_iterator storehouse_cbegin() const { return this->storehouse_collection.cbegin();}
    NodeCollection<Storehouse>::const_iterator storehouse_cend() const { return this->storehouse_collection.cend();}


    void do_deliveries(Time t){for(auto& elem: this->ramp_collection) elem.deliver_goods(t);}
    void do_package_passing();
    void do_work(Time t){for(auto& elem: this->worker_collection) elem.do_work(t);}
    bool is_consistent();

private:
    void remove_receiver(NodeCollection<Worker>& collection_, ElementID id);
    void remove_receiver(NodeCollection<Storehouse>& collection_, ElementID id);


    NodeCollection<Ramp> ramp_collection;
    NodeCollection<Worker> worker_collection;
    NodeCollection<Storehouse> storehouse_collection;
};



#endif //INFORMATYKA_PROGRAMOWANIE_SYMULACJA_FACTORY_HPP
