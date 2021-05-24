#ifndef ASTEROIDS_PLAYER_H
#define ASTEROIDS_PLAYER_H

#include <iostream>
#include <vector>
#include "entity.h"

//#include "../common.h"


class Player : public Entity {
private:
    bool alive = true;

public:
    Player();

    explicit Player(sf::Texture texture);

    void move() override;

    void rotate(int dir);

    void shoot(std::vector<Bullet> &bullets);

    void draw(sf::RenderWindow *win) override;
};


#endif
