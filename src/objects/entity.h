#ifndef OBJECTS_H
#define OBJECTS_H

#include "../common.h"
#include <iostream>
#include <vector>

class Entity {
public:
    position pos = {};
    double rotation = 0;       // rotation in degrees
    double radius = 0;

    virtual void move() = 0;

    bool out_of_bounds() const;

    double get_x() const;

    double get_y() const;

    position get_pos() const;

    double get_radius() const;
};

class Flying_entity : public Entity {
public:
    position velocity = {};

    Flying_entity();

    void move() override;
};

class Bullet : public Flying_entity {
public:
    Bullet(position pos, position velocity);
};


#endif
