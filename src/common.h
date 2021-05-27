#ifndef ASTEROIDS_COMMON_H
#define ASTEROIDS_COMMON_H

#define WINDOW_TITLE "Asteroids"
#define WIDTH 1000
#define HEIGHT 1000
#define FRAMERATE_LIMIT 60

#define WIDTH_CENTER (WIDTH*1.0/2)
#define HEIGHT_CENTER (HEIGHT*1.0/2)

#define SPAWN_AREA_SIZE 200

#define ROTATION_UP 270

#define DIRECTION_LEFT -1
#define DIRECTION_RIGHT 1

#define MIN_ASTEROID_ROTATION 1
#define MAX_ASTEROID_ROTATION 5

#define PLAYER_ROTATION_SPAN 4
#define PLAYER_STEP 9
#define PLAYER_INITIAL_LIVES 1
#define PLAYER_INVINCIBLE_TIME 200
#define PLAYER_INVINCIBLE_BLINK_RATE (FRAMERATE_LIMIT/4)

#define PLAYER_RADIUS 10
#define BULLET_RADIUS 1
#define BIG_ASTEROID_RADIUS 23
#define MEDIUM_ASTEROID_RADIUS 15
#define SMALL_ASTEROID_RADIUS 10

#define BULLET_VELOCITY 5
#define MIN_ASTEROID_VELOCITY 1
#define MAX_ASTEROID_VELOCITY 5

// asteroids created aster destroying larger one
#define NEW_MEDIUM_ASTEROIDS 2
#define NEW_SMALL_ASTEROIDS 3

#define NEW_ASTEROID_DEGREE_RANGE 30

#define TEXTURE_SIZE 50
#define TEXTURE_CENTER TEXTURE_SIZE*1.0/2

#define TEXTURE_PATH (std::string)"../src/textures/" // debug
//#define TEXTURE_PATH (std::string)"./textures/"    // normal


struct position {
    double x;
    double y;
};

#endif
