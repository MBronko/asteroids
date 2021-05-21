#include "utils.h"
#include <iostream>

double to_radians(int degree) {
    return degree * 1.0 / 180;
}

bool objects_overlap(objects &object1, objects &object2){
    double radius = object1.get_radius() + object2.get_radius();
    return std::abs(object1.get_x()-object2.get_x()) < radius && std::abs(object1.get_y()-object2.get_y()) < radius;
}