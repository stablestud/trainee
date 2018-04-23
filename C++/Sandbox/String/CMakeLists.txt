cmake_minimum_required(VERSION 2.6)
project(string)

add_executable(string main.cpp)

install(TARGETS string RUNTIME DESTINATION bin)
