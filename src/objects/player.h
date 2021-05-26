#ifndef ASTEROIDS_PLAYER_H
#define ASTEROIDS_PLAYER_H

#include <iostream>
#include <vector>
#include "entity.h"


class Player : public Entity {
private:

public:
    int lives = PLAYER_INITIAL_LIVES;
    int invincible = 0;

    Player();

    void move() override;

    void rotate(int dir);

    void shoot(std::vector<Bullet> &bullets);

    void reset();
};


#endif
