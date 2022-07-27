#include <gtest/gtest.h>
#include <thread>
#include <TimeProvider.h>
#include <TimeProviderSim.h>

TEST(TimeProvider, LifeTime){
    TimeProvider& test = TimeProvider::getInstance();
    auto time_now_1 = test.time_now();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    auto time_now_2 = test.time_now();
    int duration = abs(time_now_2.count()-time_now_1.count());
    EXPECT_TRUE(duration < 1050);
}

TEST(TimeProviderSim, LifeTime){
    TimeProviderSim& test = TimeProviderSim::getInstance();
    auto time_now_1 = test.time_now();
    test.advance_time(milliseconds(1000));
    auto time_now_2 = test.time_now();
    int duration = abs(time_now_2.count()-time_now_1.count());
    EXPECT_TRUE(duration < 1050);
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
