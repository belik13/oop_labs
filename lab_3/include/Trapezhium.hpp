//
// Created by bmaks on 30.10.2024.
//

#ifndef LAB_3_TRAPEZHIUM_HPP
#define LAB_3_TRAPEZHIUM_HPP

#include "Figure.hpp"

class Trapezhium : public Figure {
public:
    size_t point_count() const {
        return 4;
    };

    Trapezhium();

    operator double const();

    friend std::istream& operator>>(std::istream& is, Trapezhium& t);
};


#endif //LAB_3_TRAPEZHIUM_HPP
