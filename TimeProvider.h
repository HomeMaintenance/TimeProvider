#pragma once
#include <chrono>

using milliseconds = std::chrono::duration<double, std::milli>;
using steady_clock = std::chrono::steady_clock;
using system_clock = std::chrono::system_clock;

class TimeProvider{
public:
    enum ClockMode{
        steady,
        system
    };


    ClockMode getMode();

    static TimeProvider* getInstance(ClockMode mode = ClockMode::steady);

    virtual milliseconds get_time() const;

    virtual void sleep_for(const milliseconds& duration);

protected:
    TimeProvider();
    virtual ~TimeProvider();
    void setMode(ClockMode mode);

    static TimeProvider* _timeprovider;

private:
    TimeProvider(TimeProvider const&) = delete;
    void operator=(TimeProvider const&)  = delete;
    ClockMode mode;
};
