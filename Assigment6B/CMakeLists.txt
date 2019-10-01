cmake_minimum_required(VERSION 3.15)
project(Assigment6B)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -pthread -Wall -Wextra")

add_executable(Assigment6B main.cpp)
target_link_libraries(Assigment6B ${Boost_LIBRARIES})
