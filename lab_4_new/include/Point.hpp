

//
// Created by bmaks on 31.10.2024.
//

#ifndef LAB_4_POINT_HPP
#define LAB_4_POINT_HPP

#include <iostream>
#include <cmath>

template<class T>
class Point {
public:
    T x,y;

    Point() : x(0), y(0) {};

    Point(T x, T y) : x(x), y(y){};

    friend std::istream& operator>>(std::istream& is, Point<T>& p) {
        is >> p.x >> p.y;

        return is;
    };

    friend std::ostream& operator<<(std::ostream& os, Point<T>& p) {
        std::cout << p.x << p.y;

        return os;
    };

    double distance(Point<T> &other) {
        T d1 = other.x - this->x;
        T d2 = other.y - this->y;

        return std::sqrt(d1 * d1 - d2 * d2);
    };

    bool operator==(Point<T> &other) {
        return ((this->x == other.x) && (this->y == other.y));
    };

    bool operator!=(Point &other) {
        return !(*this == other);
    }
};

#endif //LAB_4_POINT_HPP

