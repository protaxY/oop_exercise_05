#ifndef OOP_EXERCISE_03_PENTAGON_H
#define OOP_EXERCISE_03_PENTAGON_H

#include "Figure.h"

class Pentagon: public Figure{
public:
    Pentagon(Cord center, double radius);
    double Area() override;
    void print() override;
};
#endif
