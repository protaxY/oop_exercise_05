#include "Cord.h"

Cord::Cord(){
    X = 0;
    Y = 0;
}

Cord::Cord(const double &curX, const double &curY){
    SetPosition(curX, curY);
}

void Cord::SetPosition(const double &curX, const double &curY){
    X = curX;
    Y = curY;
}

Cord operator+(const Cord &lhs, const Cord &rhs){
    Cord result(lhs.X + rhs.X, lhs.Y + rhs.Y);
    return result;
}

Cord operator-(const Cord &lhs, const Cord &rhs){
    Cord result(lhs.X - rhs.X, lhs.Y - rhs.Y);
    return result;
}

Cord operator*(const double &lhs, const Cord &rhs){
    Cord result(lhs * rhs.Y, lhs * rhs.Y);
    return result;
}

Cord operator*(const Cord &lhs, const double &rhs){
    Cord result(lhs.X * rhs, lhs.Y * rhs);
    return result;
}

std::ostream& operator<<(std::ostream &out, const Cord &cord){
    out << "(" << cord.X << "," << cord.Y << ")";
    return out;
}