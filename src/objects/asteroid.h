#ifndef ASTEROIDS_ASTEROID_H
#define ASTEROIDS_ASTEROID_H

#include <iostream>
#include <vector>
#include "../common.h"
#include "entity.h"


class Asteroid : public Flying_entity {
public:
    Asteroid(position pos, position velocity);

    virtual std::vector<Asteroid> create_new_objects() = 0;
};

class Big_asteroid : public Asteroid {
public:
    Big_asteroid(position pos, position velocity);

    std::vector<Asteroid> create_new_objects();
};

class Medium_asteroid : public Asteroid {
public:
    Medium_asteroid(position pos, position velocity);

    std::vector<Asteroid> create_new_objects();
};

class Small_asteroid : public Asteroid {
public:
    Small_asteroid(position pos, position velocity);

    std::vector<Asteroid> create_new_objects();
};

#endif
