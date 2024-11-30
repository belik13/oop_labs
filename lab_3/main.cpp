#include <iostream>
#include "include/Figure.hpp"
#include "include/Rhombus.hpp"
#include "include/Rect.hpp"
#include "include/Trapezhium.hpp"

int main () {
    int n;

    std::cout << "Enter the amount of Figures";
    std::cin >> n;

    Figure* figure = new Figure[n];

    double s = 0;

    for (int i = 0; i != n; ++i) {
        std::cout << "Enter the Type of Figure to Store( 1 - Rect, 2 - Rhombus, 3 - Trapezhium)\n";

        int cmd;
        std::cin >> cmd;

        if (cmd == 1) {
            Rect r;
            std::cin >> r;

            s += double (r);

            figure[i] = std::move(r);
        } else if (cmd == 2) {
            Rhombus r;
            std::cin >> r;

            s += double (r);

            figure[i] = std::move(r);
        } else if (cmd == 3) {
            Trapezhium t;
            std::cin >> t;

            s += double (t);

            figure[i] = std::move(t);
        }
    }

    std::cout << "Total area = " << s << std::endl;

    return 0;
    // 1 1 2 2 3 1 2 0

   // 0 0
  //  0 1
    //1 1
   // 1 0

   // 0 0
   // 3 0
   // 2 1
   // 1 1

//if ((p1.distance(p2) == p3.distance(p4)) && (p2.distance(p3) == p3.distance(p1))) {
//    std::cout << "HERE";
//    if (arePerpendicular(p1, p2, p3)
//        && arePerpendicular(p2, p3, p1)
//        && arePerpendicular(p3, p4, p2)
//        && arePerpendicular(p4, p1, p3)) {
//        return is;
//    }
//

//    double Point::distance(Point &other) {
//        double x = other.x - this->x;
//        double y = other.y - this->y;
//
//        return std::sqrt(x*x + y*y);
//    }
}