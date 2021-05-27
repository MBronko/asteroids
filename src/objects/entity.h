#ifndef OBJECTS_H
#define OBJECTS_H

#include "../common.h"
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"

class Entity {
public:
    position pos = {};
    position velocity = {};
    double radius = 0;
    sf::Sprite sprite;

    virtual void move();

    bool out_of_bounds() const;

    void draw(sf::RenderWindow *win);
};

class Bullet : public Entity {
public:
    Bullet(position pos, position velocity);
};


#endif
