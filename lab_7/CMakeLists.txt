cmake_minimum_required(VERSION 3.26)
project(lab_7)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab_7 main.cpp
        src/npc.cpp
        src/knight.cpp
        src/elf.cpp
        src/druid.cpp
        include/observer.hpp
        include/fight.hpp
        include/factory.hpp)
