cmake_minimum_required(VERSION 3.26)
project(lab_3)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab_3 main.cpp
        include/Figure.hpp
        src/Rhombus.cpp
        src/Point.cpp
        include/Rect.hpp
        src/Rect.cpp
        include/Trapezhium.hpp
        src/Trapezhium.cpp)
