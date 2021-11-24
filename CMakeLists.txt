cmake_minimum_required(VERSION 3.17)
project(ArduinoHAL)
set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES Examples/examples.cpp)

add_executable(ArduinoHAL ${SOURCE_FILES})