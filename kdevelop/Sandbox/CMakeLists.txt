cmake_minimum_required(VERSION 2.6)
project(sandbox)

add_executable(sandbox main.cpp)

install(TARGETS sandbox RUNTIME DESTINATION bin)
