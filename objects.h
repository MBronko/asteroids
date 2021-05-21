#ifndef OBJECTS_H
#define OBJECTS_H

#include "common.h"
#include <iostream>
#include <vector>
//#include "player.h"


class objects {
public:
    double x = 0;
    double y = 0;
    int rotation = 0;       // rotation in degrees
    double radius = 0;

    virtual void move() {};

    double get_x() const;

    double get_y() const;

    double get_radius() const;
};

class flying_object : public objects {
public:
    double x_vel = 0;
    double y_vel = 0;
};

class bullet : public flying_object {
public:
    bullet(double x, double y, double x_vel, double y_vel);

    void move() override;
};


#endif
