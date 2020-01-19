

#ifndef INFORMATYKA_PROGRAMOWANIE_SYMULACJA_REPORTS_HPP
#define INFORMATYKA_PROGRAMOWANIE_SYMULACJA_REPORTS_HPP

#include "factory.hpp"

class IntervalReportNotifier{
public:
    explicit IntervalReportNotifier(TimeOffset to): to_(to) {};
    bool should_generate_report(Time t) const {return t%this->to_ == 1;};
private:
    TimeOffset to_;
};

class SpecificTurnsReportNotifier{
public:
    explicit SpecificTurnsReportNotifier(std::set<Time> turns): turns_(std::move(turns)) {};
    bool should_generate_report(Time t) const {return this->turns_.find(t)!=this->turns_.end();}
private:
    std::set<Time> turns_;
};




#endif //INFORMATYKA_PROGRAMOWANIE_SYMULACJA_REPORTS_HPP
