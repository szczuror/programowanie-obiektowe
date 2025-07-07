cmake_minimum_required(VERSION 3.15)

project(
  lab5
  VERSION 1.0
  LANGUAGES CXX)

add_executable(lab5 main.cpp
    Sensor.hpp
    SensorCollection.cpp
    SensorCollection.hpp)