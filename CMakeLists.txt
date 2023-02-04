cmake_minimum_required(VERSION 3.23)
project(Azalea)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(lib/spdlog)
add_subdirectory(lib/glfw)
add_subdirectory(lib/glad/cmake)

glad_add_library(glad2 MX API gl:core=4.0)

if(${CMAKE_BUILD_TYPE} EQUAL Debug)
    add_compile_definitions(AZALEA_DEBUG)
endif()

file(GLOB_RECURSE SRC src/**.cpp)
list(APPEND ${SRC} include/azalea/core/Entry.hpp)
add_library(Azalea STATIC ${SRC})
target_include_directories(Azalea PUBLIC include)
target_link_libraries(Azalea spdlog glfw glad2)

add_subdirectory(test)