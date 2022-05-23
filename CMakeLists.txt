cmake_minimum_required(VERSION 3.17)
project(ArduinoHAL)
set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES Examples/C_Introduction/examples.cpp)

add_executable(ArduinoHAL ${SOURCE_FILES})