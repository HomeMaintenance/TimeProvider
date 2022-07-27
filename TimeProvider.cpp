#include "TimeProvider.h"
#include <iostream>

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

milliseconds TimeProvider::get_time() const{
    return steady_clock::now().time_since_epoch();
}
