

#ifndef INFORMATYKA_PROGRAMOWANIE_SYMULACJA_SIMULATION_HPP
#define INFORMATYKA_PROGRAMOWANIE_SYMULACJA_SIMULATION_HPP

#include "factory.hpp"


void simulate(Factory& f, TimeOffset d, std::function<void (Factory&, Time)> rf);


#endif //INFORMATYKA_PROGRAMOWANIE_SYMULACJA_SIMULATION_HPP
