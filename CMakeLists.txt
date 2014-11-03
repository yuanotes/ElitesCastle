cmake_minimum_required(VERSION 2.8.4)
project(ElitesCastle)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Shape.cpp main.cpp OverlapTest.cpp Car.cpp)
add_executable(ElitesCastle ${SOURCE_FILES})