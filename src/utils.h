#ifndef ASTEROIDS_UTILS_H
#define ASTEROIDS_UTILS_H

#include "objects/objects.h"

double to_radians(int degree);

bool objects_overlap(position pos1, double radius1, position pos2, double radius2);

#endif
