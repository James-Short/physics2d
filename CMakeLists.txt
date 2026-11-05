cmake_minimum_required(VERSION 3.16)

project(Physics2D LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(Physics2D main.cpp)

find_package(SDL3 CONFIG REQUIRED)

target_link_libraries(Physics2D PRIVATE SDL3::SDL3)