cmake_minimum_required(VERSION 3.17)
project(TextBar)

set(CMAKE_CXX_STANDARD 14)

add_executable(TextBar main.cpp TextBar.cpp TextBar.h)

include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(TextBar sfml-system sfml-window sfml-graphics sfml-audio sfml-network)