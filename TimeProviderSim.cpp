#include "TimeProviderSim.h"


TimeProviderSim& TimeProviderSim::getInstance(){
    static TimeProviderSim instance;
    return instance;
}

TimeProviderSim::TimeProviderSim():TimeProvider(){}

TimeProviderSim::~TimeProviderSim(){}

milliseconds TimeProviderSim::time_now() const{
    return time;
}

void TimeProviderSim::advance_time(const milliseconds& _time){
    time += _time;
}
