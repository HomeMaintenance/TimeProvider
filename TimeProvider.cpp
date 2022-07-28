#include "TimeProvider.h"
#include <iostream>
#include <thread>

TimeProvider* TimeProvider::_timeprovider = nullptr;

TimeProvider* TimeProvider::getInstance(){
    if(_timeprovider==nullptr){
        _timeprovider = new TimeProvider();
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
    return steady_clock::now().time_since_epoch();
}
