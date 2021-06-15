cmake_minimum_required(VERSION 3.17)
project(ArduinoHAL)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        ArduinoHAL
        Examples/cExamples.cpp
        Examples/cExamples.h
        Examples/main.cpp
        Examples/halUsage.h
        Examples/halUsage.cpp
        HAL/Arduino.cpp
        HAL/Arduino.h
        HAL/binary.h
        HAL/pins_arduino.h
        HAL/avrAbstraction.h
        HAL/Print.h
        HAL/Print.cpp
)