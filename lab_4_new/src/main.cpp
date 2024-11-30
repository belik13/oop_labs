#include <iostream>
#include "../include/Rect.hpp"
#include "../include/Trapezhium.hpp"
#include "../include/Rhombus.hpp"
#include "../include/Array.hpp"

#define TYPE double

int main() {
    int figuresCount = 0;

    std::cout << "Введите количество фигур\n" ;
    std::cin >> figuresCount;

    Array<std::shared_ptr<Figure<TYPE>>> figures(figuresCount);

    double s = 0;


    int cmd = 0;

    for (int i = 0; i != figuresCount; ++i) {
        std::cout << "Введите: \n"
                     "1 - для добавления Прямоугольника\n"
                     "2 - для добавления Трапеции\n"
                     "3 - для добавления Ромба\n"
                     "4 - для удаления фигуры по индексу\n"
                     "5 - для вывода всех сохраненных фигур\n";

        std::cin >> cmd;
        if (cmd == 1) {
            Rect<double> rect;
            std::cin >> rect;

            std::cout << "Площадь фигуры = " << (double) rect;

            figures[i] = std::make_shared<Rect<TYPE>>(rect);
        } else if (cmd == 2) {
            Trapezhium<double> trapezhium;
            std::cin >> trapezhium;

            std::cout << "Площадь фигуры = " << (double) trapezhium;

            figures[i] = std::make_shared<Trapezhium<TYPE>>(trapezhium);
        } else if (cmd == 3) {
            Rhombus<double> rhombus;
            std::cin >> rhombus;

            std::cout << "Площадь фигуры = " << (double) rhombus;

            figures[i] = std::make_shared<Rhombus<TYPE>>(rhombus);
        } else if (cmd == 4) {
            int index = 0;
            std::cout << "Введите индекс фигуры для удаления\n";
            std::cin >> index;

            figures.remove(index);
            i -= 2;
        } else if (cmd == 5) {
            for (int j = 0; j != figures.get_size(); ++j) {
                std::cout << *(figures[j]) << "\n";
            }
            --i;
        }
    }
    return 0;
}
