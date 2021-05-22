#include "utils.h"
#include <iostream>
#include <cmath>

double to_radians(double degree) {
    return degree * 1.0 / 180;
}

bool objects_overlap(position pos1, double radius1, position pos2, double radius2) {
    double radius = radius1 + radius2;
    return std::abs(pos1.x - pos2.x) < radius && std::abs(pos1.y - pos2.y) < radius;
}

position rotate_pos(position pos, double degree){
    double rad = to_radians(degree);

    double x = pos.x * std::cos(rad) - pos.y * std::sin(rad);
    double y = pos.y * std::cos(rad) + pos.x * std::sin(rad);

    return {x, y};
}