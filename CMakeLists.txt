cmake_minimum_required(VERSION 3.10)
project(heulpad VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# global collect 
file(GLOB SOURCES "src/*.cpp")

add_executable(heulpad ${SOURCES})

add_subdirectory(src/commands)
