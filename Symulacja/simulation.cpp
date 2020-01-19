

#include "simulation.hpp"

void simulate(Factory& f, TimeOffset d, std::function<void (Factory&, Time)> rf){
    for(Time t = 1; t <= d; t++){
        f.do_deliveries(t);
        f.do_package_passing();
        f.do_work(t);
        rf(f, t);
    }
}