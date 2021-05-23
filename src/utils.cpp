#include "utils.h"
#include <iostream>
#include <cmath>

double to_radians(double degree) {
    return degree * M_PI / 180;
}

double to_degree(double radian){
    return radian * 180 / M_PI;
}

bool objects_overlap(position pos1, double radius1, position pos2, double radius2) {
    double radius = radius1 + radius2;
    return std::abs(pos1.x - pos2.x) < radius && std::abs(pos1.y - pos2.y) < radius;
}

double random_range(double min, double max){
    return (double)(min + (int)random() % (int)(max - min));
}

position rotate_pos(position pos, double degree){
    double rad = to_radians(degree);

    double x = pos.x * std::cos(rad) - pos.y * std::sin(rad);
    double y = pos.y * std::cos(rad) + pos.x * std::sin(rad);

    return {x, y};
}

position velocity_towards_center(position pos){
    double x_off = WIDTH_CENTER - pos.x;
    double y_off = HEIGHT_CENTER - pos.y;

    double new_rotation = 2 * M_PI - std::atan(y_off/x_off);

    position vel = {MAX_ASTEROID_VELOCITY, 0};
    double rotation_offset = random_range(-NEW_ASTEROID_DEGREE_RANGE, NEW_ASTEROID_DEGREE_RANGE);
    std::cout << x_off << " " << y_off << " " << std::atan(y_off/x_off) << " " << to_degree(new_rotation) << " " << rotation_offset << std::endl;
    rotation_offset = 0;
    return rotate_pos(vel, shorten_rotation(to_degree(new_rotation) + rotation_offset));
}


