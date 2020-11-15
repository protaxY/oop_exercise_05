#ifndef OOP_EXERCISE_03_CORD_H
#define OOP_EXERCISE_03_CORD_H

#include <iostream>

struct Cord{
    double X;
    double Y;
    Cord();
    Cord(const double &curX, const double &curY);
    void SetPosition(const double &curX, const double &curY);
    friend Cord operator+(const Cord &lhs, const Cord &rhs);
    friend Cord operator-(const Cord &lhs, const Cord &rhs);
    friend Cord operator*(const double &lhs, const Cord &rhs);
    friend Cord operator*(const Cord &lhs, const double &rhs);
    friend std::ostream& operator<<(std::ostream &out, const Cord &cord);
};
#endif