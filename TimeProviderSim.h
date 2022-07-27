#pragma once
#include <chrono>
#include "TimeProvider.h"

using milliseconds = std::chrono::duration<double, std::milli>;

class TimeProviderSim: public TimeProvider{
public:
    static TimeProviderSim& getInstance();

    virtual milliseconds time_now() const override;

    virtual void advance_time(const milliseconds& time);

private:
    TimeProviderSim(TimeProviderSim const&) = delete;
    void operator=(TimeProviderSim const&)  = delete;
    TimeProviderSim();
    ~TimeProviderSim();

    milliseconds time;
};
