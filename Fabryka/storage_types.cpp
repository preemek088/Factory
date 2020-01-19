//
// Created by Kacper on 19/01/2020.
//

#include "storage_types.hpp"

Package PackageQueue::pop() {
    if(this->get_queue_type()==PackageQueueType::LIFO){
        Package result = Package(std::move(this->queue.back()));
        this->queue.pop_back();
        return result;
    }
    if(this->get_queue_type()==PackageQueueType::FIFO){
        Package result = Package(std::move(this->queue.front()));
        this->queue.pop_front();
        return result;
    }
    return Package();
}