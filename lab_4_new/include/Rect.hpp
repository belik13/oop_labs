//
// Created by bmaks on 09.11.2024.
//

#ifndef LAB_4_RECT_HPP
#define LAB_4_RECT_HPP

#include <cstdint>
#include "Figure.hpp"

template<class T>
class Rect : public Figure<T> {
public:
    using Figure<T>::Figure;
    Rect();
    Rect(const Rect<T>& t);
    size_t point_count () const override {
        return 4;
    }

    operator double() const override;

    template<class C>
    friend std::istream& operator>>(std::istream& is, Rect<C>& r);
};

template<class T>
Rect<T>::Rect() {
    this->points = std::vector(this->point_count(), Point<T>());
}

template <class T>
Rect<T>::Rect (const Rect<T>& t) {
    for (uint64_t i = 0; i < t.points.size(); ++i) {
        this->points.push_back(t.points[i]);
    }
}

template<class T>
bool arePerpendicular(const Point<T>& a, const Point<T>& b, const Point<T>& c) {
    double dx1 = b.x - a.x;
    double dy1 = b.y - a.y;
    double dx2 = c.x - a.x;
    double dy2 = c.y - a.y;
    return dx1 * dx2 + dy1 * dy2 == 0;
}

template<class T>
std::istream &operator>>(std::istream &is, Rect<T> &r) {
    for (int i = 0; i != r.point_count(); ++i) {
        is >> r.points[i];
    }

    Point<T> p1 = r.points[0];
    Point<T> p2 = r.points[1];
    Point<T> p3 = r.points[2];
    Point<T> p4 = r.points[3];

    if ((p1.distance(p2) == p3.distance(p4)) && (p2.distance(p3) == p4.distance(p1))) {
        if (arePerpendicular(p1, p2, p4)
            && arePerpendicular(p2, p3, p1)
            && arePerpendicular(p3, p4, p2)
            && arePerpendicular(p4, p1, p3)) {
            return is;
        }

    }

    std::cout << "It is not a Rect\n";
    for (int i = 0; i != r.point_count(); ++i) {
        r.points[i] = Point<T>(0,0);
    }

    return is;
}

template<class T>
Rect<T>::operator double() const {
    Point<T> p1 = this->points[0], p2 = this->points[1], p3 = this->points[2];
    double a = p1.distance(p2);
    double b = p2.distance(p3);

    return a * b;
}

#endif //LAB_4_RECT_HPP
