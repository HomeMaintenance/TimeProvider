#pragma once
#include <chrono>

using milliseconds = std::chrono::duration<double, std::milli>;
using steady_clock = std::chrono::steady_clock;

class TimeProvider{
public:
    static TimeProvider& getInstance();

    virtual milliseconds time_now() const;

protected:
    TimeProvider();
    ~TimeProvider();

private:
    TimeProvider(TimeProvider const&) = delete;
    void operator=(TimeProvider const&)  = delete;
};
