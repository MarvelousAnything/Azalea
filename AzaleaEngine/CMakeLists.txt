cmake_minimum_required(VERSION 3.20)
project(AzaleaEngine)

set(SOURCE_DIRS
        src
        src/Core
        src/Window)

# Sources common to all platforms
foreach (SOURCE_DIR ${SOURCE_DIRS})
    file(GLOB SOURCES
            ${SOURCE_DIR}/*.cpp
            EXCLUDE ${dir}/Platform/*)
    list(APPEND SRC ${SOURCES})
endforeach ()

# Platform specific sources
if (WIN32)
    file(GLOB_RECURSE PLATFORM_SRC src/Platform/Windows/**.cpp)
    list(APPEND SRC ${PLATFORM_SRC})
elseif (UNIX)
    file(GLOB_RECURSE PLATFORM_SRC src/Platform/Unix/**.cpp)
    list(APPEND SRC ${PLATFORM_SRC})
elseif (APPLE)
    file(GLOB_RECURSE PLATFORM_SRC src/Platform/MacOS/**.cpp)
    list(APPEND SRC ${PLATFORM_SRC})
else ()
    message(FATAL_ERROR "Unsupported platform")
endif ()

add_library(AzaleaEngine STATIC ${SRC} ${PLATFORM_SRC})
target_include_directories(AzaleaEngine PUBLIC include)