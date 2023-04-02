cmake_minimum_required(VERSION 3.20)
project(AzaleaEngine)

set(SOURCE_DIRS
        src
        src/Core
        src/Window)

set(PLATFORM_LIBRARIES)

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
    message(STATUS "Platform: UNIX")

    file(GLOB_RECURSE PLATFORM_SRC src/Platform/Unix/**.cpp)
    list(APPEND SRC ${PLATFORM_SRC})

    find_package(OpenGL REQUIRED)
    find_package(glfw3 3.3 REQUIRED)
    set(PLATFORM_LIBRARIES
            glfw
            GLEW
            OpenGL::GL
)
else ()
    message(FATAL_ERROR "Unsupported platform")
endif ()

add_library(AzaleaEngine STATIC ${SRC})
target_include_directories(AzaleaEngine PUBLIC include)
target_link_libraries(AzaleaEngine PUBLIC ${PLATFORM_LIBRARIES})