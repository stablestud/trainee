cmake_minimum_required(VERSION 2.6)
project(digit_sort_algorithm)

add_executable(digit_sort_algorithm main.cpp)

install(TARGETS digit_sort_algorithm RUNTIME DESTINATION bin)
