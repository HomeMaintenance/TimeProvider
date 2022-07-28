#pragma once
#include <chrono>

using milliseconds = std::chrono::duration<double, std::milli>;
using steady_clock = std::chrono::steady_clock;

class TimeProvider{
public:
    static TimeProvider* getInstance();

    virtual milliseconds get_time() const;

    virtual void sleep_for(const milliseconds& duration);

protected:
    TimeProvider();
    virtual ~TimeProvider();

    static TimeProvider* _timeprovider;

private:
    TimeProvider(TimeProvider const&) = delete;
    void operator=(TimeProvider const&)  = delete;
};
