//
// Created by bmaks on 26.10.2024.
//

#include "../include/Point.hpp"
#include <cmath>

Point::Point() {
    this->x = 0.;
    this->y = 0.;
}

Point::Point(double x, double y) {
    this->x = x;
    this->y = y;
}

bool Point::operator==(Point &other) {
    return (this->x == other.x && this->y == other.y);
}

bool Point::operator!=(Point &other) {
    return (this->x != other.x || this->y != other.y);
}

double Point::distance(Point &other) {
    double x = other.x - this->x;
    double y = other.y - this->y;

    return std::sqrt(x*x + y*y);
}

std::istream& operator>>(std::istream& is, Point& p) {
    is >> p.x >> p.y;
    return is;
}

std::ostream& operator<<(std::ostream& os, Point& p) {
    os << p.x << ", " << p.y;
    return os;
}
