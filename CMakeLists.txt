cmake_minimum_required(VERSION 3.23)
project(Azalea)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SRC src/**.cpp)
add_library(Azalea STATIC ${SRC} include/azalea/core/Entry.hpp)
target_include_directories(Azalea PUBLIC include)

