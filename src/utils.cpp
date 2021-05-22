#include "utils.h"
#include <iostream>

double to_radians(int degree) {
    return degree * 1.0 / 180;
}

bool objects_overlap(position pos1, double radius1, position pos2, double radius2) {
    double radius = radius1 + radius2;
    return std::abs(pos1.x - pos2.x) < radius && std::abs(pos1.y - pos2.y) < radius;
}
