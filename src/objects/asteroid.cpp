#include "asteroid.h"
#include "ctime"
#include <random>

Asteroid::Asteroid(position pos, position velocity) : Flying_object() {
    this->pos = pos;
    this->velocity = velocity;
}

Big_asteroid::Big_asteroid(position pos, position velocity) : Asteroid(pos, velocity) {
    this->radius = BIG_ASTEROID_RADIUS;
}

std::vector<Asteroid> Big_asteroid::create_new_objects() {
    std::vector<Asteroid> res = {};
//    res.push_back();
    return res;
}

Medium_asteroid::Medium_asteroid(position pos, position velocity) : Asteroid(pos, velocity) {
    this->radius = MEDIUM_ASTEROID_RADIUS;
}

std::vector<Asteroid> Medium_asteroid::create_new_objects() {
    return std::vector<Asteroid>();
}

Small_asteroid::Small_asteroid(position pos, position velocity) : Asteroid(pos, velocity) {
    this->radius = SMALL_ASTEROID_RADIUS;
}

std::vector<Asteroid> Small_asteroid::create_new_objects() {
    return std::vector<Asteroid>();
}
