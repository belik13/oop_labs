//
// Created by bmaks on 30.11.2024.
//

#ifndef LAB_4_NEW_ARRAY_HPP
#define LAB_4_NEW_ARRAY_HPP

//
// Created by bmaks on 31.10.2024.
//

#ifndef LAB_4_ARRAY_HPP
#define LAB_4_ARRAY_HPP

#include <memory>
#include <iostream>

template<class T>
class Array{
private:
    int size;
    std::shared_ptr<T[]> data;

public:
    Array() : size(0), data{nullptr} {}

    Array(size_t size) : size(size) {
        data = std::shared_ptr<T[]>(new T[size]);
    }

    Array(const std::initializer_list<T>& list) {
        data = std::shared_ptr<T[]>(new T[list.get_size()]);


        int i = 0;
        for (auto &c : list) {
            data[i++] = c;
        }

        size = list.size();
    }

    double area() const {
        double total = 0.0;

        for (int i = 0; i < size; ++i) {
            total += data[i]->operator double;
        }

        return total;
    }

    void remove(int index) {
        for (int i = index + 1; i < size; ++i) {
            data[i - 1] = data[i];
        }
    }

    T& operator[](size_t index) {
        if (index < 0 || size <= index) throw std::invalid_argument("Index is out of range!");
        return data[index];
    }

    int get_size() const {
        return size;
    }
};


#endif //LAB_4_ARRAY_HPP


#endif //LAB_4_NEW_ARRAY_HPP
