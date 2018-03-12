cmake_minimum_required(VERSION 2.6)
project(ramaro)

add_executable(ramaro main.cpp)

install(TARGETS ramaro RUNTIME DESTINATION bin)
