project(AzaleaTest)

include_directories(include)

add_executable(AzaleaTest src/main.cpp)
target_link_libraries(AzaleaTest Azalea)
