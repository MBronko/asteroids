#ifndef ASTEROIDS_ASTEROID_H
#define ASTEROIDS_ASTEROID_H

#include <iostream>
#include <vector>
#include "common.h"
#include "objects.h"


class asteroid : public flying_object {
public:
    asteroid(double x, double y, double x_vel, double y_vel);

    virtual std::vector<asteroid> destroy() = 0;
};

class big_asteroid : public asteroid {
public:
    big_asteroid(double x, double y, double x_vel, double y_vel);

    void move() override;

    std::vector<asteroid> destroy() override;
};

class medium_asteroid : public asteroid {
public:
    medium_asteroid(double x, double y, double x_vel, double y_vel);

    void move() override;

    std::vector<asteroid> destroy() override;
};

class small_asteroid : public asteroid {
public:
    small_asteroid(double x, double y, double x_vel, double y_vel);

    void move() override;

    std::vector<asteroid> destroy() override;
};

#endif
