cmake_minimum_required(VERSION 3.10)

project(undercore)

add_executable(undercore main.cpp)

install(TARGETS undercore RUNTIME DESTINATION bin)
