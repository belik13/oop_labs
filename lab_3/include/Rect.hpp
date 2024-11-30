//
// Created by bmaks on 29.10.2024.
//

#ifndef LAB_3_RECT_HPP
#define LAB_3_RECT_HPP

#include "Figure.hpp"

class Rect : public Figure {
public:
    Rect();

    size_t point_count () const {
        return 4;
    }

    operator double() const;

    friend std::istream& operator>>(std::istream& is, Rect& r);
};


#endif //LAB_3_RECT_HPP
