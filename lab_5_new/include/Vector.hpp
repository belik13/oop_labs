//
// Created by bmaks on 10.11.2024.
//

#ifndef LAB_5_VECTOR_HPP
#define LAB_5_VECTOR_HPP

#include <iostream>
#include <memory>
#include <cstdint>

template<class T, class Allocator = std::allocator<T>>
class Vector {
private:
    Allocator allocator;
    size_t _size;
    size_t _capacity;
    T* data;

public:
    Vector() : _size(0), _capacity(0),data(nullptr) {};

    Vector(const Allocator& allocator1) : allocator(allocator1),_capacity(0), _size(0),data(nullptr) {};

    ~Vector() {
        clear();
        allocator.deallocate(data,_capacity);
    }

    void push_back(const T& value) {
        if (_size == _capacity) {
            if (_capacity == 0) {
                reserve(1);
            } else {
                reserve(_capacity * 2);
            }
        }

        data[_size] = value;
        ++_size;
    }

    void pop_back() {
        if (_size > 0) {
            --_size;
        }
    }

    size_t size() const noexcept {
        return _size;
    }

    void reserve(size_t new_capacity) {
        if (new_capacity > _capacity) {
            T* new_data = allocator.allocate(new_capacity);

            for (size_t i = 0; i != _size; ++i) {
                new_data[i] = data[i];
            }

            allocator.deallocate(data, _capacity);

            data = new_data;
            _capacity = new_capacity;
        }
    }


    void clear() {
        for (size_t i = 0; i != _size; ++i) {
            data[i] = T();
        }

        _size = 0;
    }

    T& operator[](size_t pos) {
        return data[pos];
    }

    const T& operator[](size_t pos) const {
        return data[pos];
    }
};

#endif //LAB_5_VECTOR_HPP
