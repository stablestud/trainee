cmake_minimum_required(VERSION 2.6)
project(namespace)

add_executable(namespace main.cpp)

install(TARGETS namespace RUNTIME DESTINATION bin)
