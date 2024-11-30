#include <iostream>
#include "../include/Thirteen.hpp"

int main() {
//    Thirteen a = (std::string("A14"));
//    Thirteen b = (std::string("12314"));
//    a = a - b;
//    a.print(std::cout);
//

    Thirteen t1 = { 'A', 'B' };
    Thirteen t2 = { 'A', 'A' };
    Thirteen t3 = { '1' };

    Thirteen t4 = t1-t2;
    std::cout << (t1 - t2 == t3);

    return 0;
}
