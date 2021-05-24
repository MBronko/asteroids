#include "asteroid.h"
#include <ctime>
#include <random>
#include <iostream>
#include <memory>
#include "../utils.h"

Asteroid::Asteroid(position pos, position velocity) : Flying_entity() {
    this->pos = pos;
    this->velocity = velocity;
}

Big_asteroid::Big_asteroid(position pos, position velocity) : Asteroid(pos, velocity) {
    this->radius = BIG_ASTEROID_RADIUS;

    sf::Texture texture;
    texture.loadFromFile(TEXTURE_PATH + "big_asteroid.png");
    sprite.setTexture(texture);
}

std::vector<std::shared_ptr<Asteroid>> Big_asteroid::create_new_objects() {
    std::vector<std::shared_ptr<Asteroid>> res = {};

    for (int i = 0; i < NEW_MEDIUM_ASTEROIDS; i++) {
        position new_vel = {};
        new_vel.x = random_range(-MAX_ASTEROID_VELOCITY, MAX_ASTEROID_VELOCITY);
        new_vel.y = random_range(-MAX_ASTEROID_VELOCITY, MAX_ASTEROID_VELOCITY);

        position new_pos = {pos.x + new_vel.x, pos.y + new_vel.y};
        res.push_back(std::make_shared<Medium_asteroid>(Medium_asteroid(new_pos, new_vel)));
    }
    return res;
}

void Big_asteroid::draw(sf::RenderWindow *win) {

}

Medium_asteroid::Medium_asteroid(position pos, position velocity) : Asteroid(pos, velocity) {
    this->radius = MEDIUM_ASTEROID_RADIUS;

    sf::Texture texture;
    texture.loadFromFile(TEXTURE_PATH + "medium_asteroid.png");
    sprite.setTexture(texture);
}

std::vector<std::shared_ptr<Asteroid>> Medium_asteroid::create_new_objects() {
    std::vector<std::shared_ptr<Asteroid>> res = {};

    for (int i = 0; i < NEW_SMALL_ASTEROIDS; i++) {
        position new_vel = {};
        new_vel.x = random_range(-MAX_ASTEROID_VELOCITY, MAX_ASTEROID_VELOCITY);
        new_vel.y = random_range(-MAX_ASTEROID_VELOCITY, MAX_ASTEROID_VELOCITY);

        position new_pos = {pos.x + new_vel.x, pos.y + new_vel.y};
        res.push_back(std::make_shared<Small_asteroid>(Small_asteroid(new_pos, new_vel)));
    }
    return res;
}

void Medium_asteroid::draw(sf::RenderWindow *win) {

}

Small_asteroid::Small_asteroid(position pos, position velocity) : Asteroid(pos, velocity) {
    this->radius = SMALL_ASTEROID_RADIUS;

    sf::Texture texture;
    texture.loadFromFile(TEXTURE_PATH + "small_asteroid.png");
    sprite.setTexture(texture);
}

std::vector<std::shared_ptr<Asteroid>> Small_asteroid::create_new_objects() {
    return std::vector<std::shared_ptr<Asteroid>>();
}

void Small_asteroid::draw(sf::RenderWindow *win) {

}
