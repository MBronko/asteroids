#ifndef ASTEROIDS_PLAYER_H
#define ASTEROIDS_PLAYER_H

#include <iostream>
#include <vector>
#include "entity.h"


class Player : public Entity {
public:
    int invincible = 0;
    int shoot_cooldown = 0;

    Player();

    void move() override;

    void accelerate();

    void rotate(int dir);

    void shoot(std::vector<Bullet> &bullets);

    void reset();
};


#endif
