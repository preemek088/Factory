

#include "factory.hpp"
#include "types.hpp"
#include <istream>
#include <string>
#include <sstream>
#include <vector>

void Factory::remove_receiver(NodeCollection<Worker>& collection_, ElementID id) {
    if(collection_.find_by_id(id) == collection_.end()) return;
    ReceiverType type_= (*collection_.find_by_id(id)).get_receiver_type();
    if(type_ == ReceiverType::WORKER){
        for(auto& elem : this->ramp_collection){
            elem.receiver_preferences_.remove_receiver(&(*collection_.find_by_id(id)));
        }
    }
    if(type_ == ReceiverType::STOREHOUSE){
        for(auto& elem : this->worker_collection){
            elem.receiver_preferences_.remove_receiver(&(*collection_.find_by_id(id)));
        }
    }
    collection_.remove_by_id(id);
}

void Factory::remove_receiver(NodeCollection<Storehouse>& collection_, ElementID id) {
    if(collection_.find_by_id(id) == collection_.end()) return;
    ReceiverType type_= (*collection_.find_by_id(id)).get_receiver_type();
    if(type_ == ReceiverType::WORKER){
        for(auto& elem : this->ramp_collection){
            elem.receiver_preferences_.remove_receiver(&(*collection_.find_by_id(id)));
        }
    }
    if(type_ == ReceiverType::STOREHOUSE){
        for(auto& elem : this->worker_collection){
            elem.receiver_preferences_.remove_receiver(&(*collection_.find_by_id(id)));
        }
    }
    collection_.remove_by_id(id);
}

void Factory::do_package_passing() {
    for(auto& elem: this->ramp_collection) elem.send_package();
    for(auto& elem: this->worker_collection) elem.send_package();
}

enum class NodeColor { UNVISITED, VISITED, VERIFIED };

bool has_reachable_storehouse(PackageSender* sender, std::map<const PackageSender*, NodeColor>& node_colors) {
    if (node_colors[sender] == NodeColor::VERIFIED) return true;
    node_colors[sender] = NodeColor::VISITED;
    if (sender->receiver_preferences_.get_preferences().empty()) throw std::logic_error("Niespójna");

    bool more_than_one_receiver = false;
    for (auto &elem: sender->receiver_preferences_.get_preferences()) {
        if (elem.first->get_receiver_type() == ReceiverType::STOREHOUSE) more_than_one_receiver = true;
        else {
            IPackageReceiver *receiver_ptr = elem.first;
            auto worker_ptr = dynamic_cast<Worker *>(receiver_ptr);
            auto sendrecv_ptr = dynamic_cast<PackageSender *>(worker_ptr);
            if (worker_ptr != sender) {
                more_than_one_receiver = true;
                if (node_colors[sendrecv_ptr] == NodeColor::UNVISITED) {
                    try {
                        has_reachable_storehouse(sendrecv_ptr, node_colors);
                    }
                    catch (std::logic_error &) {
                        throw std::logic_error("Niespójna");
                    }
                }
            }
        }
    }
    node_colors[sender] = NodeColor::VERIFIED;
    if (more_than_one_receiver) {
        return true;

    }
    else throw std::logic_error("Niespójna");
}

bool Factory::is_consistent() {
    std::map<const PackageSender*, NodeColor> node_colors;
    for(const auto& elem: this->worker_collection) node_colors[&elem] = NodeColor::UNVISITED;

    for(auto& elem: this->ramp_collection){
        try{
            has_reachable_storehouse(&elem, node_colors);
        }
        catch(std::logic_error&){
            return false;
        }
    }
    return true;
}

enum class LineType{WORKER, STOREHOUSE, RAMP, LINK};

std::pair<LineType, std::map<std::string,std::string>>parse_line(std::string& line) {
    std::vector<std::string> tokens;
    std::string token;

    std::istringstream token_stream(line);
    char delimiter = ' ';

    while (std::getline(token_stream, token, delimiter)) {
        tokens.push_back(token);
    }

    LineType type;

    if (tokens[0] == "WORKER")
        type = LineType::WORKER;
    else if (tokens[0] == "LINK")
        type = LineType::LINK;
    else if (tokens[0] == "STOREHOUSE")
        type = LineType::STOREHOUSE;
    else
        type = LineType::RAMP;

    std::string temp1;
    std::string temp2;
    std::istringstream temp_string;
    std::map<std::string,std::string> map_of_tokens;
    for(auto iterator = tokens.begin() + 1; iterator!=tokens.end(); iterator++){
        temp_string = std::istringstream(*iterator);
        std::getline(temp_string, temp1, '=');
        std::getline(temp_string, temp2, '=');
        map_of_tokens[temp1]=temp2;
    }

    return std::make_pair(type, map_of_tokens);
}



std::string link_to_string(IPackageReceiver* receiver_){
    std::string result;
    if(receiver_->get_receiver_type() == ReceiverType::WORKER){
        result = " dest=worker-";
    }
    else{
        result = " dest=store-";
    }
    result += std::to_string(receiver_->get_id());
    return result;
}
