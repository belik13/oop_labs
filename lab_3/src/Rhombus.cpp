//
// Created by bmaks on 29.10.2024.
//

#include "../include/Rhombus.hpp"

Rhombus::Rhombus() {
    this->points = std::vector(this->point_count(), Point());
}


double dot_product(const Point &p1, const Point &p2, const Point &p3, const Point &p4) {
    double dx1 = p2.x - p1.x;
    double dy1 = p2.y - p1.y;
    double dx2 = p4.x - p3.x;
    double dy2 = p4.y - p3.y;
    return dx1 * dx2 + dy1 * dy2;
}

bool are_diagonals_perpendicular(const Point &p1, const Point &p2, const Point &p3, const Point &p4) {
    return std::abs(dot_product(p1, p2, p3, p4)) < 1e-9;
}

std::istream& operator>>(std::istream& is, Rhombus& r) {
    for (int i = 0; i != r.point_count(); ++i) {
        is >> r.points[i];
    }

    Point p1 = r.points[0];
    Point p2 = r.points[1];
    Point p3 = r.points[2];
    Point p4 = r.points[3];

//    bool is_rombus = false;

    if (p1.distance(p2) == p2.distance(p3) &&
        p2.distance(p3) == p3.distance(p4) &&
        p3.distance(p4) == p4.distance(p1)) {
        if (are_diagonals_perpendicular(p1,p3,p2,p4)) {
//        is_rombus = true;
            return  is;
    }
}
//    if (!is_rombus) {
        std::cout << "It is not a Rhombus";
        for (int i = 0; i != r.point_count(); ++i) {
            r.points[i] = Point(1,1);
        }
//    }

    return is;
}

Rhombus::operator double const() {
    double d1 = this->points[0].distance(this->points[1]);
    double d2 = this->points[2].distance(this->points[3]);

    return d1 * d2 / 2.;
}

