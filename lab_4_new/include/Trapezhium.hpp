//
// Created by bmaks on 09.11.2024.
//

#ifndef LAB_4_TRAPEZHIUM_HPP
#define LAB_4_TRAPEZHIUM_HPP

#include "Figure.hpp"

template<class T>
class Trapezhium : public Figure<T> {
public:
    using Figure<T>::Figure;

    size_t point_count() const override {return 4;};

    Trapezhium();

    operator double() const override;

    Point<T> centre() const override;
    template<class C>
    friend std::istream& operator>>(std::istream& is, Trapezhium<C>& t);
};

template<class T>
Trapezhium<T>::Trapezhium() {
    this->points = std::vector(this->point_count(), Point<T>());
}

template<class T>
std::istream &operator>>(std::istream &is, Trapezhium<T> &t) {
    for (int i = 0; i != t.point_count(); ++i) {
        is >> t.points[i];
    }

    Point<T> p1 = t.points[0];
    Point<T> p2 = t.points[1];
    Point<T> p3 = t.points[2];
    Point<T> p4 = t.points[3];

    double m12 = (double) (p2.y - p1.y)/(p2.x - p1.x);
    double m23 = (double) (p3.y - p2.y)/(p3.x - p2.x);
    double m14 = (double) (p4.y - p1.y)/(p4.x - p1.x);
    double m34 = (double) (p4.y - p3.y)/(p4.x - p3.x);

    if (!(m12 == m34 || m23 == m14)) {
        std::cout << "It is not a trapezium!\n";
        for (int i = 0; i < t.point_count(); ++i) {
            t.points[i] = Point<T>(0, 0);
        }
    }

    return is;
}

template<class T>
Point<T> Trapezhium<T>::centre() const{
    Point<T> p1 = this->points[0], p2 = this->points[2];

    double xc = (p1.x + p2.x) / 2.0;
    double yc = (p1.y + p2.y) / 2.0;

    return Point<T>(xc,yc);
}

template<class T>
Trapezhium<T>::operator double() const {
    Point<T> p1 = this->points[0], p2 = this->points[1], p3 = this->points[2], p4 = this->points[3];

    return abs(0.5 * (p1.x * p2.y + p2.x * p3.y + p3.x * p4.y + p4.x * p1.y -
                      p2.x * p1.y - p3.x * p2.y - p4.x * p3.y - p1.x * p4.y));
}

#endif //LAB_4_TRAPEZHIUM_HPP
