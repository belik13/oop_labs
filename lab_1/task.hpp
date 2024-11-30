#ifndef LAB_1_TASK_HPP
#define LAB_1_TASK_HPP

#include <math.h>

bool check(int x, int y) {
    if ((sqrt(x-y) == trunc(sqrt(x-y))) && (sqrt(x+y) == trunc(sqrt(x+y)))) {
        return true;
    } else {
        return false;
    }
}

std::pair<int,int> closest_pair_tonum(int upper_limit) {
    for (int i = upper_limit - 1; i > 0; --i) {
        for (int j = i - 1; j > 0; j--) {
            if (check(i,j)) {
                return std::pair<int,int>(i,j);
            }
        }
    }
    return std::pair<int,int>(0,0);
}

#endif //LAB_1_TASK_HPP
