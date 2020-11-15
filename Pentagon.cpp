#include "Pentagon.h"

Pentagon::Pentagon(Cord center, double radius):Figure(center,radius){};

double Pentagon::Area(){
    return 5 * 0.5 * sin((double) 72 / 180 * PI) * Radius * Radius;
}

void Pentagon::print(){
    for (int i = 0; i < 5; ++i){
        Cord radVector(Radius * sin((double) (i * 72) / 180 * PI), Radius * cos((double) (i * 72) / 180 * PI));
        std::cout << Center + radVector << ", ";
    }
}
