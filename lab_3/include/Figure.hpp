//
// Created by bmaks on 26.10.2024.
//

#ifndef LAB_3_FIGURE_HPP
#define LAB_3_FIGURE_HPP

#include "Point.hpp"
#include <vector>

class Figure {
    public:
        virtual size_t point_count () const {
            return 0;
        }

        friend std::istream& operator>>(std::istream& is, Figure &figure) {
            for (int i = 0; i < figure.point_count(); ++i) {
                is >> figure.points[i];
            }

            return is;
        }

        friend std::ostream& operator<<(std::ostream& os, Figure& figure) {
            std::cout << figure.point_count();
            for (int i = 0; i != figure.point_count(); ++i) {
                os << figure.points[i] << " ";
            }

            return os;
        }


        // copy

        Figure& operator=(Figure& other) {
            if (this == &other) {
                return *this;
            }

            this->points = std::vector(other.point_count(), Point());

            for (int i = 0; i < other.point_count(); ++i) {
                this->points[i] = other.points[i];
            }

            return *this;
        }

        Figure& operator=(Figure&& other) {
            if (this == &other) {
                return *this;
            }
            this->points = std::move(other.points);
            return *this;
        }

    bool operator==(Figure& other) {
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

    protected:
        std::vector<Point> points;
};

#endif //LAB_3_FIGURE_HPP
