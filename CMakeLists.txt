cmake_minimum_required(VERSION 3.23)
project(Azalea)

set(CMAKE_CXX_STANDARD 17)

add_library(Azalea STATIC include/azalea/Azalea.hpp src/core/Application.cpp include/azalea/core/Entry.hpp)
target_include_directories(Azalea PUBLIC include)

add_subdirectory(test)