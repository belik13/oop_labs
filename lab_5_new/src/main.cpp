//
// Created by bmaks on 30.11.2024.
//
#include <iostream>

#include "../include/Allocator.hpp"
#include "../include/Vector.hpp"

int main() {

    Vector<int, Allocator<int>> vector;

    vector.reserve(10);
    vector.push_back(5);

    std::cout << vector[0];
    return 0;
}
