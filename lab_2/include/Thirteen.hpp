#ifndef LAB_2_THIRTEEN_CPP
#define LAB_2_THIRTEEN_HPP
#pragma once

#include <iostream>
#include <cstdint>
#include <map>

class Thirteen {
private:
    unsigned char *values = nullptr;
    int64_t capacity = 0;

    void resize(int64_t new_capacity);

public:
    Thirteen();
    Thirteen(const std::string& n);
    Thirteen(const Thirteen& other);
    Thirteen(const std::initializer_list< unsigned char> &t);
    Thirteen(const size_t & n, unsigned char t = 0);

    virtual ~Thirteen();


    std::string ALPHABET_HELP = "0123456789ABC";
    std::map<unsigned char,int> ALPHABET{
             {'0', 0},
             {'1', 1},
             {'2', 2},
             {'3', 3},
             {'4', 4},
             {'5', 5},
             {'6', 6},
             {'7', 7},
             {'8', 8},
             {'9', 9},
             {'A', 10},
             {'B', 11},
             {'C', 12}
    };
    const int64_t BASIC_CAPACITY = 1;

    Thirteen& operator=(const Thirteen& other);
    Thirteen& operator=(Thirteen&& other) noexcept;

    bool operator==(Thirteen& other);
    bool operator>(Thirteen& other);
    bool operator<(Thirteen& other);
    bool operator!=(Thirteen& other);

    Thirteen operator+(Thirteen& other);
    Thirteen operator-(Thirteen& other);

    std::ostream &print(std::ostream &os);

    bool is_empty() noexcept;
};

#endif //LAB_2_THIRTEEN_CPP
