#include "TimeProvider.h"
#include <iostream>


TimeProvider& TimeProvider::getInstance(){
    static TimeProvider instance;
    return instance;
}

TimeProvider::TimeProvider(){
    std::cout << "TimeProvider::TimeProvider()" << std::endl;
}

TimeProvider::~TimeProvider(){
    std::cout << "TimeProvider::~TimeProvider()" << std::endl;
}

milliseconds TimeProvider::time_now() const{
    return steady_clock::now().time_since_epoch();
}
