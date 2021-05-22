#ifndef ASTEROIDS_COMMON_H
#define ASTEROIDS_COMMON_H

#define WIDTH 1000
#define HEIGHT 1000

#define WIDTH_CENTER (WIDTH/2)
#define HEIGHT_CENTER (HEIGHT/2)

#define ROTATION_RIGHT 0
#define ROTATION_UP 90
#define ROTATION_LEFT 180
#define ROTATION_DOWN 270

#define ROTATE_LEFT 1
#define ROTATE_RIGHT -1

#define ROTATION_SPAN 2
#define PLAYER_STEP 5

#define PLAYER_RADIUS 10
#define BULLET_RADIUS 5
#define BIG_ASTEROID_RADIUS 30
#define MEDIUM_ASTEROID_RADIUS 20
#define SMALL_ASTEROID_RADIUS 10

#define shorten_rotation(x) (x<0?x+360:(x>=360?x-360:x))

#define BULLET_VELOCITY 5

struct position{
    double x;
    double y;
};

#endif