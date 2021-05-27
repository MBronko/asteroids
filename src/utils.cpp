#include "utils.h"
#include <cmath>

double to_radians(double degree) {
    return degree * M_PI / 180;
}

double to_degree(double radian) {
    return radian * 180 / M_PI;
}

bool objects_overlap(position pos1, double radius1, position pos2, double radius2) {
    double radius = radius1 + radius2;
    return std::abs(pos1.x - pos2.x) < radius && std::abs(pos1.y - pos2.y) < radius;
}

double random_range(double min, double max) {
    return (double) (min + (int) rand() % (int) (max - min));
}

int signum(double number) {
    if (number == 0) return 0;
    return number < 0 ? -1 : 1;
}

int random_sign() {
    int num = rand() % 2;
    return num == 0 ? -1 : 1;
}

position rotate_pos(position pos, double degree) {
    double rad = to_radians(degree);

    double x = pos.x * std::cos(rad) - pos.y * std::sin(rad);
    double y = pos.y * std::cos(rad) + pos.x * std::sin(rad);

    return {x, y};
}

double calculate_velocity(position pos) {
    return std::sqrt(pos.x * pos.x + pos.y * pos.y);
}

position random_asteroid_velocity() {
    double x = random_sign() * random_range(MIN_ASTEROID_VELOCITY, MAX_ASTEROID_VELOCITY);
    double y = random_sign() * random_range(MIN_ASTEROID_VELOCITY, MAX_ASTEROID_VELOCITY);
    return {x, y};
}

position velocity_towards_center(position pos) {
    double x_off = WIDTH_CENTER - pos.x;
    double y_off = HEIGHT_CENTER - pos.y;

    double new_rotation = std::atan(y_off / x_off);

    position vel = {random_range(MIN_ASTEROID_VELOCITY, MAX_ASTEROID_VELOCITY), 0};

    double rotation_offset = random_range(-NEW_ASTEROID_DEGREE_RANGE, NEW_ASTEROID_DEGREE_RANGE);
    rotation_offset += x_off < 0 ? 180 : 0;  // flip by 180 degrees if point is on the right side of board

    return rotate_pos(vel, shorten_rotation(to_degree(new_rotation) + rotation_offset));
}
