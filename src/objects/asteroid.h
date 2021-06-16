#ifndef ASTEROIDS_ASTEROID_H
#define ASTEROIDS_ASTEROID_H

#include <iostream>
#include <vector>
#include <memory>
#include "SFML/Graphics.hpp"
#include "../common.h"
#include "entity.h"


class Asteroid : public Entity {
public:
    int points = 0;

    Asteroid(position pos, position velocity);

    virtual std::vector<std::shared_ptr<Asteroid>> create_new_objects(double delta_time) = 0;
};

class Big_asteroid : public Asteroid {
public:
    Big_asteroid(position pos, position velocity);

    std::vector<std::shared_ptr<Asteroid>> create_new_objects(double delta_time) override;
};

class Medium_asteroid : public Asteroid {
public:
    Medium_asteroid(position pos, position velocity);

    std::vector<std::shared_ptr<Asteroid>> create_new_objects(double delta_time) override;
};

class Small_asteroid : public Asteroid {
public:
    Small_asteroid(position pos, position velocity);

    std::vector<std::shared_ptr<Asteroid>> create_new_objects(double delta_time) override;
};

#endif
