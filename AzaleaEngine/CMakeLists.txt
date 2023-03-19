cmake_minimum_required(VERSION 3.20)
project(AzaleaEngine)



file(GLOB_RECURSE SRC src/**.cpp EXCLUDE src/Platform)
add_library(AzaleaEngine STATIC ${SRC})
target_include_directories(AzaleaEngine PUBLIC include)