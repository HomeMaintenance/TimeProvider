cmake_minimum_required(VERSION 3.20)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)

project(TimeProvider CXX)

add_subdirectory(test)

add_library(TimeProvider
    TimeProvider.cpp
    TimeProvider.h
)
target_include_directories(TimeProvider PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(TimeProviderSim
    TimeProviderSim.h
    TimeProviderSim.cpp
)
target_link_libraries(TimeProviderSim PUBLIC TimeProvider)
