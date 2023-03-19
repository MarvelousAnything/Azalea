cmake_minimum_required(VERSION 3.20)
project(AzaleaTest)



file(GLOB_RECURSE SRC src/**.cpp)
add_executable(AzaleaTest ${SRC})
target_link_libraries(AzaleaTest AzaleaEngine)