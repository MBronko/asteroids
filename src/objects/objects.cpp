#include "objects.h"

bool Object::out_of_bounds() const {
    double x = pos.x;
    double y = pos.y;

    return x < 0 || x > WIDTH || y < 0 || x > HEIGHT;
}

double Object::get_x() const {
    return pos.x;
}

double Object::get_y() const {
    return pos.y;
}

position Object::get_pos() const {
    return pos;
}

double Object::get_radius() const {
    return radius;
}

void Flying_object::move() {
    pos.x += velocity.x;
    pos.y += velocity.y;
}

Bullet::Bullet(position pos, position velocity) {
    this->pos = pos;
    this->velocity = velocity;
    this->radius = BULLET_RADIUS;
}