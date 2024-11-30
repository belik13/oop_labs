//
// Created by bmaks on 29.10.2024.
//

#ifndef LAB_3_RHOMBUS_HPP
#define LAB_3_RHOMBUS_HPP

#include "Figure.hpp"

class Rhombus : public Figure {
public:
    size_t point_count() const {
        return 4;
    }

    Rhombus();
    operator double const();

    friend std::istream& operator>>(std::istream& is, Rhombus& r);
};


#endif //LAB_3_RHOMBUS_HPP
