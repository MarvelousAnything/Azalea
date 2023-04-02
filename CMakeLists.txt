cmake_minimum_required(VERSION 3.20)
project(Azalea)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -O3")

if( CMAKE_BUILD_TYPE STREQUAL "Debug" )
    add_compile_definitions(AZALEA_DEBUG)
else()
    add_compile_definitions(AZALEA_RELEASE)
endif()

add_subdirectory(AzaleaEngine)
add_subdirectory(AzaleaTest)
