cmake_minimum_required(VERSION 2.6)
project(stack_oop)

add_executable(stack_oop stack_oop.cpp)

install(TARGETS stack_oop RUNTIME DESTINATION bin)
