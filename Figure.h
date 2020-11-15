#ifndef OOP_EXERCISE_03_FIGURE_H
#define OOP_EXERCISE_03_FIGURE_H

#include "Cord.h"
#include <iostream>
#include <math.h>

const double PI = 3.14159265358979323846264338327950288419716939937510;

class Figure{
protected:
    Cord Center;
    double Radius = 0;
public:
    Figure(Cord center, double radius);
    Cord GetCenter();
    virtual double Area() = 0;
    virtual void print() = 0;
};
#endif