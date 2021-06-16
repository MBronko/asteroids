#ifndef ASTEROIDS_PLAYER_H
#define ASTEROIDS_PLAYER_H

#include <iostream>
#include <vector>
#include "entity.h"


class Player : public Entity {
public:
    double invincible = 0;
    double shoot_cooldown = 0;

    Player();

    void move(double delta_time) override;

    void accelerate(double delta_time);

    void decelerate(double delta_time, double a);

    void rotate(double delta_time, int dir);

    void shoot(std::vector<Bullet> &bullets);

    void reset();
};


#endif
