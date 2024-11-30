#include <iostream>
#include "task.hpp"

int main() {
    int x;

    std::cin >> x;

    std::pair<int,int> ans = closest_pair_tonum(x);
    std::cout << ans.first << " " << ans.second;

    return 0;
}
