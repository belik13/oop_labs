//
// Created by bmaks on 26.10.2024.
//

#ifndef LAB_3_POINT_HPP
#define LAB_3_POINT_HPP

#include <iostream>

class Point {
    public:
        double x,y;

        Point();
        Point(double x, double y);

        friend std::istream& operator>>(std::istream& is, Point& p);
        friend std::ostream& operator<<(std::ostream& os, Point& p);

        double distance(Point &other);

        bool operator==(Point &other);
        bool operator!=(Point &other);
};


#endif //LAB_3_POINT_HPP
