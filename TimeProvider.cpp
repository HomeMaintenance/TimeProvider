#include "TimeProvider.h"
#include <iostream>
#include <thread>

TimeProvider* TimeProvider::_timeprovider = nullptr;

void TimeProvider::setMode(TimeProvider::ClockMode _mode){
    mode = _mode;
}

TimeProvider::ClockMode TimeProvider::getMode(){
    return mode;
}

TimeProvider* TimeProvider::getInstance(TimeProvider::ClockMode mode){
    if(_timeprovider==nullptr){
        _timeprovider = new TimeProvider();
        _timeprovider->setMode(mode);
    }
    return _timeprovider;
}

TimeProvider::TimeProvider(){
    std::cout << "TimeProvider::TimeProvider()" << std::endl;
}

TimeProvider::~TimeProvider(){
    delete _timeprovider;
    _timeprovider = nullptr;
    std::cout << "TimeProvider::~TimeProvider()" << std::endl;
}

void TimeProvider::sleep_for(const milliseconds& duration){
    std::this_thread::sleep_for(duration);
}

milliseconds TimeProvider::get_time() const{
    milliseconds result;
    switch(mode){
        case ClockMode::system:
            result = system_clock::now().time_since_epoch();
            break;
        case ClockMode::steady:
        default:
            result = steady_clock::now().time_since_epoch();
            break;
    }
    return result;
}
