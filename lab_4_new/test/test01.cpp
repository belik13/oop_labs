//
// Created by bmaks on 30.11.2024.
//
#include <gtest/gtest.h>

#include "../include/rect.hpp"
#include "../include/rhombus.hpp"
#include "../include/trapezhium.hpp"
#include "../include/Point.hpp"

#include <vector>


TEST(Compare, All) {
std::vector<Point<int>> points = { Point<int>(0, 0), Point<int>(0, 1), Point<int>(1, 1), Point<int>(0, 1) };
Rect<int> r1(points);
Rect<int> r2(r1);

ASSERT_TRUE(r1 == r2);
}
TEST(Square, All) {
std::vector<Point<float>> points_1 = { Point<float>(1., 1.), Point<float>(2., 2.), Point<float>(3., 1.), Point<float>(2., 0.) };
Rect<float> r1(points_1);

std::vector<Point<float>> points_2 = { Point<float>(0., 0.), Point<float>(0., 1.), Point<float>(1., 1.), Point<float>(1., 0.) };
Trapezhium<float> t1(points_2);
ASSERT_TRUE((double) t1 == 1);

}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}