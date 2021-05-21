#ifndef ASTEROIDS_UTILS_H
#define ASTEROIDS_UTILS_H

#include "objects.h"

double to_radians(int degree);

bool objects_overlap(objects object1, objects object2);

#endif
