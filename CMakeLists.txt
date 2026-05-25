cmake_minimum_required(VERSION 3.26)
project(EcoMision)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(EcoMision ${SOURCES})
target_include_directories(EcoMision PRIVATE src)
