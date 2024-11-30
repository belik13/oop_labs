cmake_minimum_required(VERSION 3.26)
project(lab_6)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab_6
        include/druid.hpp
        include/knight.hpp
        include/elf.hpp
        src/druid.cpp
        include/factory.hpp
        src/knight.cpp
        src/npc.cpp
        src/elf.cpp
        include/observer.hpp
        test/npc.cpp
        test/main.cpp
        test/visitor.cpp)

set(GTEST_DIR "C:/clionLibrary/googletest-main")
include_directories(${GTEST_DIR}/include)
add_subdirectory(${GTEST_DIR} ${CMAKE_BINARY_DIR}/gtest)
target_link_libraries(lab_6 gtest gtest_main)