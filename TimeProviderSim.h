#pragma once
#include <chrono>
#include "TimeProvider.h"

using milliseconds = std::chrono::duration<double, std::milli>;

class TimeProviderSim: public TimeProvider{
public:
    static TimeProviderSim* getInstance();

    virtual milliseconds get_time() const override;

    virtual void advance_time(const milliseconds& time);

    virtual void sleep_for(const milliseconds& duration) override;

protected:
    static TimeProviderSim* _timeprovider;

private:
    TimeProviderSim(TimeProviderSim const&) = delete;
    void operator=(TimeProviderSim const&)  = delete;
    TimeProviderSim();
    virtual ~TimeProviderSim();

    milliseconds time;
};
