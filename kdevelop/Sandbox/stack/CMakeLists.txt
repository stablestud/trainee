cmake_minimum_required(VERSION 2.6)
project(stack)

add_executable(stack main.cpp)

install(TARGETS stack RUNTIME DESTINATION bin)
