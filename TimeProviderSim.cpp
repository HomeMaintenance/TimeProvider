#include "TimeProviderSim.h"


TimeProviderSim* TimeProviderSim::_timeprovider = nullptr;

TimeProviderSim* TimeProviderSim::getInstance(){
    if(_timeprovider==nullptr){
        _timeprovider = new TimeProviderSim();
    }
    return _timeprovider;
}

TimeProviderSim::TimeProviderSim():TimeProvider(){}

TimeProviderSim::~TimeProviderSim(){
    delete _timeprovider;
    _timeprovider = nullptr;
}

milliseconds TimeProviderSim::get_time() const{
    return time;
}

void TimeProviderSim::advance_time(const milliseconds& _time){
    time += _time;
}
