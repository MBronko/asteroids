#include "objects.h"

double objects::get_x() const {
    return x;
}

double objects::get_y() const {
    return y;
}

double objects::get_radius() const {
    return radius;
}


bullet::bullet(double x, double y, double x_vel, double y_vel) {
    this->x = x;
    this->y = y;
    this->x_vel = x_vel;
    this->y_vel = y_vel;
    this->radius = BULLET_RADIUS;
}

void bullet::move() {

}