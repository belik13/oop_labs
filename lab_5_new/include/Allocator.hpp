//
// Created by bmaks on 10.11.2024.
//

#ifndef LAB_5_ALLOCATOR_HPP
#define LAB_5_ALLOCATOR_HPP

#include <iostream>
#include <list>


template<class T>
class Allocator {
public:
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using size_type = size_t;

    Allocator() {};

    T* allocate(size_t size) {
        T* new_pointer = static_cast<T*>(calloc(size,sizeof(T)));

        if (new_pointer) {
            used_pointers.push_back(new_pointer);
            return new_pointer;
        }

        throw std::bad_alloc();
    }

    void deallocate(T* block, size_t size) {
        used_pointers.remove(block);
        free(block);
    }

    ~Allocator() {
        for (T* c : used_pointers) {
            free(c);
        }
    }

private:
    std::list<T*> used_pointers;
};

#endif //LAB_5_ALLOCATOR_HPP
