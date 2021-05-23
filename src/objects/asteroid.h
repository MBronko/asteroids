#ifndef ASTEROIDS_ASTEROID_H
#define ASTEROIDS_ASTEROID_H

#include <iostream>
#include <vector>
#include <memory>
#include "../common.h"
#include "entity.h"


class Asteroid : public Flying_entity {
public:
    Asteroid(position pos, position velocity);

    virtual std::vector<std::shared_ptr<Asteroid>> create_new_objects() = 0;
};

class Big_asteroid : public Asteroid {
public:
    Big_asteroid(position pos, position velocity);

    std::vector<std::shared_ptr<Asteroid>> create_new_objects() override;
};

class Medium_asteroid : public Asteroid {
public:
    Medium_asteroid(position pos, position velocity);

    std::vector<std::shared_ptr<Asteroid>> create_new_objects() override;
};

class Small_asteroid : public Asteroid {
public:
    Small_asteroid(position pos, position velocity);

    std::vector<std::shared_ptr<Asteroid>> create_new_objects() override;
};

#endif
