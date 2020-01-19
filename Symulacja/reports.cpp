

#include "reports.hpp"


std::string generate_ramp_string(const Ramp& ramp_){
    std::string result = "\nLOADING RAMP #" + std::to_string(ramp_.get_id());
    result += "\n  Delivery interval: " + std::to_string(ramp_.get_delivery_interval());
    result += "\n  Receivers:";
    std::list<ElementID> worker_ids;
    std::list<ElementID> store_ids;
    for(auto iterator = ramp_.receiver_preferences_.cbegin(); iterator != ramp_.receiver_preferences_.cend(); iterator++){
        if(iterator->first->get_receiver_type() == ReceiverType::WORKER){
            worker_ids.push_back(iterator->first->get_id());
        }
        else{
            store_ids.push_back(iterator->first->get_id());
        }
    }

    if(!worker_ids.empty()){
        for(const auto& id: worker_ids){
            result += "\n    worker #" + std::to_string(id);
        }
    }

    if(!store_ids.empty()){
        for(const auto& id: store_ids){
            result += "\n    storehouse #" + std::to_string(id);
        }
    }

    return result += "\n";
}

std::string generate_string_of_ramps(Factory& f){
    std::string result = "== LOADING RAMPS ==\n";
    for(auto iterator = f.ramp_cbegin(); iterator != f.ramp_cend(); iterator++) result += generate_ramp_string(*iterator);
    return result;
}

std::string generate_worker_string(const Worker& worker_){
    std::string result = "\n\nWORKER #" + std::to_string(worker_.get_id());
    result += "\n  Processing time: " + std::to_string(worker_.get_processing_duration());
    result += "\n  Queue time: ";
    if(worker_.get_queue()->get_queue_type() == PackageQueueType::LIFO){
        result += "LIFO";
    }
    else{
        result += "FIFO";
    }
    result += "\n  Receivers:";
    std::list<ElementID> worker_ids;
    std::list<ElementID> store_ids;
    for(auto iterator = worker_.receiver_preferences_.cbegin(); iterator != worker_.receiver_preferences_.cend(); iterator++){
        if(iterator->first->get_receiver_type() == ReceiverType::WORKER){
            worker_ids.push_back(iterator->first->get_id());
        }
        else{
            store_ids.push_back(iterator->first->get_id());
        }
    }

    if(!worker_ids.empty()){
        for(const auto& id: worker_ids){
            result += "\n    worker #" + std::to_string(id);
        }
    }

    if(!store_ids.empty()){
        for(const auto& id: store_ids){
            result += "\n    storehouse #" + std::to_string(id);
        }
    }

    return result += "\n";
}

std::string generate_string_of_workers(Factory& f){
    std::string result = "\n\n== WORKERS ==\n";
    for(auto iterator = f.worker_cbegin(); iterator != f.worker_cend(); iterator++) result += generate_worker_string(*iterator);
    return result;
}

std::string generate_string_of_stores(Factory& f){
    std::string result = "\n\n== STOREHOUSES ==\n";
    for(auto iterator = f.storehouse_cbegin(); iterator != f.storehouse_cend(); iterator++) result += "\n  STOREHOUSE #" + std::to_string(iterator->get_id()) + "\n";
    return result;
}




std::string generate_string_for_worker(const Worker& worker, Time t){
    std::string result = "\nWORKER #" + std::to_string(worker.get_id());
    result += "\n  Queue: ";
    if(worker.is_processing()){
        result += "#" + std::to_string(worker.get_processed_id()) + " (pt = " + std::to_string(t - worker.get_package_processing_start_time()) + ")";
    }
    if(!worker.get_queue()->empty()){
        for(const auto& elem: *worker.get_queue()){
            result += ", #" + std::to_string(elem.get_id());
        }
    }
    return result + "\n";
}

std::string generate_workers_string(Factory& f, Time t){
    std::string result = "\n\n== WORKERS ==\n";
    for(auto iterator = f.worker_cbegin(); iterator != f.worker_cend(); iterator++) result += generate_string_for_worker(*iterator, t);
    return result;
}

std::string generate_string_for_store(const Storehouse& store){
    std::string result = "\nSTOREHOUSE #" + std::to_string(store.get_id());
    result += "\n  Queue: ";
    std::string temp_string;
    if(!store.get_queue()->empty()){
        for(const auto& elem: *store.get_queue()){
            if(!temp_string.empty()){
                temp_string += ", #" + std::to_string(elem.get_id());
            }
            else{
                temp_string += "#" + std::to_string(elem.get_id());
            }
        }
    }
    return result + temp_string + "\n";
}

std::string generate_stores_string(Factory& f){
    std::string result = "\n\n== STOREHOUSES ==\n";
    for(auto iterator = f.storehouse_cbegin(); iterator != f.storehouse_cend(); iterator++) result += generate_string_for_store(*iterator);
    return result;
}

