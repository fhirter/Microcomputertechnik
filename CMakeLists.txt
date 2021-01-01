cmake_minimum_required(VERSION 3.17)
project(ArduinoHAL)

set(CMAKE_CXX_STANDARD 14)

add_executable(ArduinoHAL main.cpp Arduino.cpp Arduino.h binary.h pins_arduino.h avrAbstraction.h Print.h Print.cpp)