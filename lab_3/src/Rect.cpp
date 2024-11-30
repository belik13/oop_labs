//
// Created by bmaks on 29.10.2024.
//

#include "../include/Rect.hpp"

Rect::Rect() {
    this->points = std::vector(this->point_count(), Point());
}

bool arePerpendicular(const Point& a, const Point& b, const Point& c) {
    double dx1 = b.x - a.x;
    double dy1 = b.y - a.y;
    double dx2 = c.x - a.x;
    double dy2 = c.y - a.y;
    return dx1 * dx2 + dy1 * dy2 == 0;
}

std::istream &operator>>(std::istream &is, Rect &r) {
    for (int i = 0; i != r.point_count(); ++i) {
        is >> r.points[i];
    }

    Point p1 = r.points[0];
    Point p2 = r.points[1];
    Point p3 = r.points[2];
    Point p4 = r.points[3];

    if ((p1.distance(p2) == p3.distance(p4)) && (p2.distance(p3) == p4.distance(p1))) {
        if (arePerpendicular(p1, p2, p4)
           && arePerpendicular(p2, p3, p1)
           && arePerpendicular(p3, p4, p2)
           && arePerpendicular(p4, p1, p3)) {
            return is;
        }

    }

    std::cout << "It is not a Rect";
    for (int i = 0; i != r.point_count(); ++i) {
        r.points[i] = Point(0,0);
    }

    return is;
}

Rect::operator double() const {
    Point p1 = points[0], p2 = points[1], p3 = points[2];
    double a = p1.distance(p2);
    double b = p2.distance(p3);

    return a * b;
}

