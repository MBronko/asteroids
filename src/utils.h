#ifndef ASTEROIDS_UTILS_H
#define ASTEROIDS_UTILS_H

#include "objects/entity.h"

double to_radians(double degree);

double to_degree(double radian);

bool objects_overlap(position pos1, double radius1, position pos2, double radius2);

position rotate_pos(position pos, double degree);

double random_range(double min, double max);

int signum(double number);

position velocity_towards_center(position pos);

#define shorten_rotation(x) (x<0?x+360:(x>=360?x-360:x))

#define stay_in_bounds(min_val, x, max_val) (std::max(min_val * 1.0, std::min(max_val * 1.0, x * 1.0)))

#endif
