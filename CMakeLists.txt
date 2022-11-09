cmake_minimum_required(VERSION 3.23)
project(Azalea)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(lib/spdlog)
add_subdirectory(lib/glfw)

add_library(Azalea STATIC include/azalea/Azalea.hpp src/core/Application.cpp include/azalea/core/Entry.hpp src/debug/Profiler.cpp src/core/Event.cpp src/core/Events.cpp src/util/GLUtil.cpp)
target_include_directories(Azalea PUBLIC include)
target_link_libraries(Azalea spdlog glfw)

add_subdirectory(test)