#ifndef ASTEROIDS_UTILS_H
#define ASTEROIDS_UTILS_H

#include "objects/entity.h"

double to_radians(double degree);

double to_degree(double radian);

bool objects_overlap(position pos1, double radius1, position pos2, double radius2);

position rotate_pos(position pos, double degree);

double random_range(double min, double max);

int signum(double number);

int random_sign();

position velocity_towards_center(position pos);

double calculate_velocity(position pos);

position random_asteroid_velocity();

#define shorten_rotation(x) (x<0?x+360:(x>=360?x-360:x))

#define modulo(x, n, cmd) if(x % n == 0)cmd

#define times(n, cmd) for(int i = 0; i < n; i++)cmd

#endif
