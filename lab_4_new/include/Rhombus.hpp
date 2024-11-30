//
// Created by bmaks on 09.11.2024.
//

#ifndef LAB_4_RHOMBUS_HPP
#define LAB_4_RHOMBUS_HPP

#include "Figure.hpp"

template<class T>
class Rhombus : public Figure<T> {
public:
    using Figure<T>::Figure;
    size_t point_count() const {
        return 4;
    }

    Point<T> centre() const override;
    Rhombus();
    operator double() const override;

    template<class C>
    friend std::istream& operator>>(std::istream& is, Rhombus<C>& r);
};

template<class T>
Rhombus<T>::Rhombus() {
    this->points = std::vector(this->point_count(), Point<T>());
}

template<class T>
double dot_product(const Point<T> &p1, const Point<T> &p2, const Point<T> &p3, const Point<T> &p4) {
    double dx1 = p2.x - p1.x;
    double dy1 = p2.y - p1.y;
    double dx2 = p4.x - p3.x;
    double dy2 = p4.y - p3.y;
    return dx1 * dx2 + dy1 * dy2;
}

template<class T>
bool are_diagonals_perpendicular(const Point<T> &p1, const Point<T> &p2, const Point<T> &p3, const Point<T> &p4) {
    return std::abs(dot_product(p1, p2, p3, p4)) < 1e-9;
}

template<class T>
std::istream& operator>>(std::istream& is, Rhombus<T>& r) {
    for (int i = 0; i != r.point_count(); ++i) {
        is >> r.points[i];
    }

    Point<T> p1 = r.points[0];
    Point<T> p2 = r.points[1];
    Point<T> p3 = r.points[2];
    Point<T> p4 = r.points[3];

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
    std::cout << "It is not a Rhombus\n";
    for (int i = 0; i != r.point_count(); ++i) {
        r.points[i] = Point<T>(0,0);
    }
//    }

    return is;
}

template<class T>
Point<T> Rhombus<T>::centre() const{
    Point<T> p1 = this->points[0], p2 = this->points[2];

    double xc = (p1.x + p2.x) / 2.0;
    double yc = (p1.y + p2.y) / 2.0;

    return Point<T>(xc,yc);
}

template<class T>
Rhombus<T>::operator double() const {
    Point<T> p1 = this->points[0], p2 = this->points[1], p3 = this->points[2], p4 = this->points[3];
    double a = p1.distance(p3);
    double b = p2.distance(p4);

    return a * b /2.;
}

#endif //LAB_4_RHOMBUS_HPP
