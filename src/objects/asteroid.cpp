#include "asteroid.h"
#include <random>
#include <memory>
#include "../utils.h"
#include "../components/view.h"

Asteroid::Asteroid(position pos, position velocity) {
    this->pos = pos;
    this->pos.rotation = (int) (rand() % 360);

    this->velocity = velocity;
    this->velocity.rotation = random_sign() * random_range(MIN_ASTEROID_ROTATION, MAX_ASTEROID_ROTATION);
}

Big_asteroid::Big_asteroid(position pos, position velocity) : Asteroid(pos, velocity) {
    this->radius = BIG_ASTEROID_RADIUS;
    this->points = BIG_ASTEROID_POINTS;

    sprite.setTexture(textures[1]);
}

std::vector<std::shared_ptr<Asteroid>> Big_asteroid::create_new_objects() {
    std::vector<std::shared_ptr<Asteroid>> res = {};

    for (int i = 0; i < NEW_MEDIUM_ASTEROIDS; i++) {
        position new_vel = random_asteroid_velocity();

        position new_pos = {pos.x + new_vel.x, pos.y + new_vel.y};
        res.push_back(std::make_shared<Medium_asteroid>(Medium_asteroid(new_pos, new_vel)));
    }
    return res;
}

Medium_asteroid::Medium_asteroid(position pos, position velocity) : Asteroid(pos, velocity) {
    this->radius = MEDIUM_ASTEROID_RADIUS;
    this->points = MEDIUM_ASTEROID_POINTS;

    sprite.setTexture(textures[2]);
}

std::vector<std::shared_ptr<Asteroid>> Medium_asteroid::create_new_objects() {
    std::vector<std::shared_ptr<Asteroid>> res = {};

    for (int i = 0; i < NEW_SMALL_ASTEROIDS; i++) {
        position new_vel = random_asteroid_velocity();

        position new_pos = {pos.x + new_vel.x, pos.y + new_vel.y};
        res.push_back(std::make_shared<Small_asteroid>(Small_asteroid(new_pos, new_vel)));
    }
    return res;
}

Small_asteroid::Small_asteroid(position pos, position velocity) : Asteroid(pos, velocity) {
    this->radius = SMALL_ASTEROID_RADIUS;
    this->points = SMALL_ASTEROID_POINTS;

    sprite.setTexture(textures[3]);
}

std::vector<std::shared_ptr<Asteroid>> Small_asteroid::create_new_objects() {
    return std::vector<std::shared_ptr<Asteroid>>();
}