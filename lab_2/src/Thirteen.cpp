//
// Created by bmaks on 25.10.2024.
//

#include "../include/Thirteen.hpp"

void Thirteen::resize(int64_t new_capacity) {
    if (new_capacity < this->capacity) {

    } else {
        if (new_capacity == this->capacity) {
            return;
        }
    }

    unsigned char *new_values = new unsigned char[new_capacity];
    for (int64_t i = 0; i < this->capacity; ++i) {
        new_values[i] = this->values[i];
    }

    delete this->values;
    this->values = new_values;
    this->capacity = new_capacity;
}

Thirteen Thirteen::operator-(Thirteen& other) {
    int64_t max = std::max(this->capacity, other.capacity);

    Thirteen temp = Thirteen(max, '\0');

    uint64_t a = 0, b = 0, remainder = 0;
    int64_t i = 0;

    for (i = 0; i < max - 1; ++i) {
        a = b = 0;

        if (i < this->capacity - 1) a = ALPHABET.at(this->values[i]);
        if (i < other.capacity - 1) b = ALPHABET.at(other.values[i]);

        if (remainder > 0) a -= remainder;

        int64_t num = a - b;

        if (num < 0) {
            if (this->values[i + 1] == '\0') {
                temp.values[0] = '0';
                temp.values[1] = '\0';
                break;
            }
            remainder = 1;
            temp.values[i] = ALPHABET_HELP[13 + num % 13];
        } else {
            remainder = 0;
            temp.values[i] = ALPHABET_HELP[num % 13];
        }
    }

    for (; i > 1; --i) { // i > 2 because we are not touching the first zero if it is present
        if (temp.values[i] == '\0' && temp.values[i - 1] == '0') temp.values[i - 1] = '\0';
    }

    return temp;
}

Thirteen Thirteen::operator+(Thirteen& other) {
    Thirteen temp;

    int64_t max = std::max(this->capacity, other.capacity);
    uint64_t a = 0, b = 0, remainder = 0;

    for (int64_t i = 0; i < max - 1; ++i) {
        a = b = 0;

        if (i < this->capacity - 1) a = ALPHABET.at(this->values[i]);
        if (i < other.capacity - 1) b = ALPHABET.at(other.values[i]);

        if (remainder == 1) a += 1;

        remainder = (a + b) / 13;

        if (temp.capacity - 1 <= i) {
            temp.resize(temp.capacity * 2);
        }

        int64_t num = a + b;

        temp.values[i] = ALPHABET_HELP[num % 13];
        temp.values[i + 1] = ALPHABET_HELP[remainder];
    }


    if (remainder) temp.values[max] = '\0';
    else temp.values[max - 1] = '\0';

    return temp;
}

Thirteen::Thirteen() {
    this->capacity = BASIC_CAPACITY;
    this->values = new unsigned char[this->capacity];
    this->values[0] = '0';
}

Thirteen::Thirteen(const Thirteen &other) {
    *this = other;
}

Thirteen::Thirteen(const std::initializer_list<unsigned char> &t) {
    int64_t len = t.size();

    this->capacity = len + 1;
    this->values = new unsigned char[this->capacity];

    for (uint64_t i = 0; i != t.size(); ++i) {
        this->values[i] = *(t.end() - 1 - i);
    }
}

Thirteen::Thirteen(const size_t & n, unsigned char t) {
    this->capacity = (int64_t) n + 1;

    this->values = new unsigned char[this->capacity];

    std::fill_n(this->values, this->capacity, t);
}

Thirteen::Thirteen(const std::string &n) {
    if (n.length() == 0) {
        return;
    }

    const int64_t len = n.length();

    this->capacity = len;
    this->values = new unsigned char[this->capacity];

    for (int64_t i = 0; i < len; ++i) {
        this->values[i] = n[len - 1 - i];
    }
}

Thirteen::~Thirteen() {
    if (this->values != nullptr) {
        delete this->values;
    }
    this->capacity = 0;
    this->values = nullptr;
}

bool Thirteen::operator>(Thirteen &other) {
    if (this->capacity < other.capacity) {
        return false;
    } else if (this->capacity > other.capacity){
        return true;
    }

    int64_t iters = this->capacity - 1;

    for (int64_t i = iters; i >= 0; --i) {
        unsigned char c1 = this->values[i], c2 = other.values[i];
//        std::cout << ALPHABET[c1] << " " << ALPHABET[c2] << std::endl;
        if (ALPHABET[c1] > ALPHABET[c2]) {
            return true;
        } else if (ALPHABET[c1] < ALPHABET[c2]) {
            return false;
        }
    }
    return false;
}

bool Thirteen::operator<(Thirteen &other) {
    return other > *this;
}

bool Thirteen::operator==(Thirteen &other) {
    if (*this > other || *this < other) return false;
    return true;
}

bool Thirteen::operator!=(Thirteen& other) {
    return !(*this == other);
}

Thirteen& Thirteen::operator=(const Thirteen& other) {
    if (this == &other)
        return *this;

    if (this->capacity != other.capacity) {
        unsigned char *temp = new unsigned char[other.capacity];
        if (this->values != nullptr) delete[] this->values;

        this->values = temp;
        this->capacity = other.capacity;
    }

    std::copy(other.values, other.values + other.capacity, this->values);
    return *this;
}

// Move assignment
Thirteen& Thirteen::operator=(Thirteen&& other) noexcept {
    if (this == &other)
        return *this;

    if (this->values != nullptr) delete[] this->values;
    this->values = other.values;
    other.values = nullptr;

    this->capacity = other.capacity;
    other.capacity = 0;

    return *this;
}

std::ostream &Thirteen::print(std::ostream &os) {
    for (int64_t i = this->capacity - 1; i >= 0; --i) {
        os << this->values[i];
    }
    os << std::endl;

    return os;
}

bool Thirteen::is_empty() noexcept {
    if (this->capacity > 0) return this->values[0] == '\0';
    return true;
}