#ifndef ASTEROIDS_PLAYER_H
#define ASTEROIDS_PLAYER_H

#include <iostream>
#include <vector>
#include "../common.h"

#include "objects.h"


class Player : public objects {
private:
    bool alive = true;

public:
    Player();

    void move() override;

    void rotate(int dir);

    void shoot(std::vector<bullet> &bullets);
};


#endif
