find_package(GTest CONFIG REQUIRED)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_executable(timeprovider_test timeprovider_test.cpp)
target_include_directories(timeprovider_test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(timeprovider_test PUBLIC TimeProvider TimeProviderSim)
target_link_libraries(timeprovider_test PUBLIC GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(timeprovider_test)
