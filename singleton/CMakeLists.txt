cmake_minimum_required(VERSION 3.20)

project(SINGLETON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(SINGLETON main.cpp Singleton.cpp Singleton.h)
