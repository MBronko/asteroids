#ifndef ASTEROIDS_ASTEROID_H
#define ASTEROIDS_ASTEROID_H

#include <iostream>
#include <vector>
#include "../common.h"
#include "objects.h"


class Asteroid : public Flying_object {
public:
    Asteroid(position pos, position velocity);

    virtual std::vector<Asteroid> destroy() = 0;
};

class Big_asteroid : public Asteroid {
public:
    Big_asteroid(position pos, position velocity);

    std::vector<Asteroid> destroy() override;
};

class Medium_asteroid : public Asteroid {
public:
    Medium_asteroid(position pos, position velocity);

    std::vector<Asteroid> destroy() override;
};

class Small_asteroid : public Asteroid {
public:
    Small_asteroid(position pos, position velocity);

    std::vector<Asteroid> destroy() override;
};

#endif
