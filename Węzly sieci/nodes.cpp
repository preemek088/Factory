#include "nodes.hpp"
#include <random>

void PackageSender::send_package() {
    if(this->sending_buffer){
        this->receiver_preferences_.choose_receiver()->receive_package(std::move(*this->sending_buffer));
        this->sending_buffer.reset();
    }
}


void Worker::do_work(Time t) {
    if(t == this->get_package_processing_start_time() + this->pd_ and this->work_buffor){
        this->push_package(std::move(*this->work_buffor));
        this->work_buffor.reset();
    }

    else{
        if(!this->work_buffor and !this->q_->empty()){
            this->work_buffor = this->q_->pop();
            this->st_ = t;
        }
    }
}

bool Worker::is_processing() const {
    if(this->work_buffor) return true;
    return false;
}


void Ramp::deliver_goods(Time t) {
    if(t % this->di_ == 1){
        Package new_package;
        this->push_package(std::move(new_package));
    }
}


IPackageReceiver* ReceiverPreferences::choose_receiver() {

    if(this->preferences_map.empty()) return nullptr;

    double random_double = this->pg_();
    double temp = 0;
    for(const auto& elem : this->preferences_map){
        temp += elem.second;
        if(random_double < temp) return elem.first;
    }
    return nullptr;
}


void ReceiverPreferences::equalise_probability_to_one() {
    if(this->preferences_map.empty()) return;
    int length = this->preferences_map.size();
    for(auto& elem : this->preferences_map) elem.second = 1.0/length;
}


void ReceiverPreferences::add_receiver(IPackageReceiver* r) {
    this->preferences_map[r] = 1;
    this->equalise_probability_to_one();
}


void ReceiverPreferences::remove_receiver(IPackageReceiver* r) {
    this->preferences_map.erase(r);
    this->equalise_probability_to_one();
}