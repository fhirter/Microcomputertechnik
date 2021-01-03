cmake_minimum_required(VERSION 3.17)
project(ArduinoHAL)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        ArduinoHAL
        cExamples.cpp
        cExamples.h
        main.cpp
        halUsage.h
        halUsage.cpp
        HAL/Arduino.cpp
        HAL/Arduino.h
        HAL/binary.h
        HAL/pins_arduino.h
        HAL/avrAbstraction.h
        HAL/Print.h
        HAL/Print.cpp
)