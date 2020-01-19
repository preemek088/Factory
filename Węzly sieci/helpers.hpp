

#ifndef INFORMATYKA_PROGRAMOWANIE_SYMULACJA_HELPERS_HPP
#define INFORMATYKA_PROGRAMOWANIE_SYMULACJA_HELPERS_HPP

#include <functional>
#include <random>
#include "types.hpp"

extern std::random_device rd;

extern std::mt19937 rng;

extern double default_probability_generator();

extern ProbabilityGenerator probability_generator;

#endif //INFORMATYKA_PROGRAMOWANIE_SYMULACJA_HELPERS_HPP
