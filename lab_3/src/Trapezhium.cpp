//
// Created by bmaks on 30.10.2024.
//


#include "../include/Trapezhium.hpp"

Trapezhium::Trapezhium() {
    this->points = std::vector(this->point_count(), Point());
}

std::istream &operator>>(std::istream &is, Trapezhium &t) {
    for (int i = 0; i != t.point_count(); ++i) {
        is >> t.points[i];
    }

    Point p1 = t.points[0];
    Point p2 = t.points[1];
    Point p3 = t.points[2];
    Point p4 = t.points[3];

    double m12 = (double) (p2.y - p1.y)/(p2.x - p1.x);
    double m23 = (double) (p3.y - p2.y)/(p3.x - p2.x);
    double m14 = (double) (p4.y - p1.y)/(p4.x - p1.x);
    double m34 = (double) (p4.y - p3.y)/(p4.x - p3.x);

    if (!(m12 == m34 || m23 == m14)) {
        std::cout << "It is not a trapezium!\n";
        for (int i = 0; i < t.point_count(); ++i) {
            t.points[i] = Point(0, 0);
        }
    }

    return is;
}

Trapezhium::operator double const () {
    Point p1 = points[0], p2 = points[1], p3 = points[2], p4 = points[3];

    return abs(0.5 * (p1.x * p2.y + p2.x * p3.y + p3.x * p4.y + p4.x * p1.y -
                      p2.x * p1.y - p3.x * p2.y - p4.x * p3.y - p1.x * p4.y));
}