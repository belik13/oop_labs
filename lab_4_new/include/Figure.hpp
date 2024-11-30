//
// Created by bmaks on 31.10.2024.
//

#ifndef LAB_4_FIGURE_HPP
#define LAB_4_FIGURE_HPP

#include "Point.hpp"
#include <vector>

template<class T>
class Figure {
public:
    virtual size_t point_count () const {
        return 0;
    }

    virtual operator double() const {
        return 0;
    };

    virtual ~Figure() noexcept{};

    friend std::istream& operator>>(std::istream& is, Figure<T> &figure) {
        for (int i = 0; i < figure.point_count(); ++i) {
            is >> figure.points[i];
        }

        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, Figure<T>& figure) {
        std::cout << figure.point_count();
        for (int i = 0; i != figure.point_count(); ++i) {
            os << figure.points[i] << " ";
        }

        return os;
    }

    // copy

    virtual Figure<T>& operator=(Figure<T>&& other) {
        if (this == &other) {
            return *this;
        }
        this->points = std::move(other.points);
        return *this;
    }

    virtual Figure<T>& operator=(const Figure<T>& other) {
        if (this == &other)
            return *this;

        this->points = std::vector(other.point_count(), Point<T>());
        for (int i = 0; i < other.point_count(); ++i) {
            this->points[i] = other.points[i];
        }

        return *this;
    }

    virtual bool operator==(Figure<T>& other) {
        if (this->point_count() != other.point_count()) {
            return false;
        }

        for (int i = 0; i != other.point_count(); ++i) {
            if (this->points[i] != other.points[i]) {
                return false;
            }
        }

        return true;
    }

    Figure() noexcept {
        points = std::vector(point_count(), Point<T>());
    }

    Figure(const Figure<T>& f) {
        *this = f;
    }

    Figure(const Figure<T>&& f) {
        *this = std::move(f);
    }

    Figure(std::vector<Point<T>> p) {
        points.clear();
        for (size_t i = 0; i < p.size(); ++i) {
            points.push_back(p[i]);
        }
    }

protected:
    std::vector<Point<T>> points;
};

#endif //LAB_4_FIGURE_HPP
