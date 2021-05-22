#ifndef OBJECTS_H
#define OBJECTS_H

#include "../common.h"
#include <iostream>
#include <vector>
//#include "player.h"


class Object {
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

class Flying_object : public Object {
public:
    position velocity = {};

    Flying_object();

    void move() override;
};

class Bullet : public Flying_object {
public:
    Bullet(position pos, position velocity);
};


#endif
