cmake_minimum_required(VERSION 3.19)
project(rocketlander)

set(CMAKE_CXX_STANDARD 14)

include_directories(/usr/local/include)

set(SOURCE_FILES main.cpp rocket.cpp rocket.h util.cpp mac.h windows.h)
add_executable(rocketlander ${SOURCE_FILES})


find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(rocketlander sfml-system sfml-window sfml-graphics sfml-audio sfml-network)