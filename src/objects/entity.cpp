#include "entity.h"

bool Entity::out_of_bounds() const {
    double x = pos.x;
    double y = pos.y;

    return x < 0 || x > WIDTH || y < 0 || x > HEIGHT;
}

double Entity::get_x() const {
    return pos.x;
}

double Entity::get_y() const {
    return pos.y;
}

position Entity::get_pos() const {
    return pos;
}

double Entity::get_radius() const {
    return radius;
}

void Flying_entity::move() {
    pos.x += velocity.x;
    pos.y += velocity.y;
}

Flying_entity::Flying_entity() {
    rotation = (int)(random() % 360);
}


Bullet::Bullet(position pos, position velocity) {
    this->pos = pos;
    this->velocity = velocity;
    this->radius = BULLET_RADIUS;
}

void Bullet::draw(sf::RenderWindow *win) {

}
