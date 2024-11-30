//
// Created by bmaks on 30.11.2024.
//
#include <gtest/gtest.h>
#include "../include/Thirteen.hpp"


TEST(Initializations, All) {
Thirteen t1 = { 'C', 'A', '3' };
Thirteen t2 = Thirteen(3, 'A');
Thirteen t3 = Thirteen();
Thirteen t4 = Thirteen(0, 'A');

t4 = t2;
ASSERT_TRUE(t4 == t2);

t2 = std::move(t1);
ASSERT_TRUE(t1.is_empty());
ASSERT_TRUE(t4 != t2);

Thirteen t5 = Thirteen(t4);
Thirteen t6 = Thirteen(std::move(t4));
ASSERT_TRUE(t5 == t6);
}


TEST(Comparison, All) {
Thirteen t1 = { '8' };
Thirteen t2 = { 'A' };


t1 = { '8', 'A' };
t2 = { 'A', 'B' };

ASSERT_TRUE(t2 > t1);

Thirteen t3 = std::string("168");
ASSERT_TRUE(t3 > t1);
ASSERT_TRUE(t1 < t3);

ASSERT_TRUE(!(t1 > t1));
}



int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}