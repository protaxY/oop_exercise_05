#include "Figure.h"
#include "math.h"

Figure::Figure(Cord center, double radius){
    Center = center;
    Radius = radius;
}

Cord Figure::GetCenter(){
    return Center;
}