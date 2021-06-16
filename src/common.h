#ifndef ASTEROIDS_COMMON_H
#define ASTEROIDS_COMMON_H

// game balance config

// simple units constants
#define WIDTH 1000
#define HEIGHT 1000
#define FRAMERATE_LIMIT 60
#define SPAWN_AREA_SIZE 200 // size of squares where asteroids spawn
#define PLAYER_INITIAL_LIVES 3

#define NEW_MEDIUM_ASTEROIDS 2 // asteroids created aster destroying larger one
#define NEW_SMALL_ASTEROIDS 3

#define NEW_ASTEROID_DEGREE_RANGE 30 // max angle offset of new asteroid (0 means asteroid is targeted towards center)

#define BIG_ASTEROID_POINTS 100
#define MEDIUM_ASTEROID_POINTS 150
#define SMALL_ASTEROID_POINTS 200


// [s] seconds
#define NEW_ASTEROID_SPAWN_RATE 2
#define PLAYER_SHOOT_COOLDOWN 0.17
#define PLAYER_INVINCIBLE_TIME 3
#define PLAYER_INVINCIBLE_BLINK_RATE 0.2


// [deg/s] degrees per second
#define MIN_ASTEROID_ROTATION_SPEED 60
#define MAX_ASTEROID_ROTATION_SPEED 300
#define PLAYER_ROTATION_SPEED 240


// [unit/s] units per second
#define BULLET_VELOCITY 600
#define MIN_ASTEROID_VELOCITY 60
#define MAX_ASTEROID_VELOCITY 300
#define MAX_PLAYER_VELOCITY 500


// [unit/s^2] units per second^2
#define PLAYER_ACCELERATION 600
#define PLAYER_PASSIVE_DECELERATION 120
#define PLAYER_ACTIVE_DECELERATION 250


// non-config constants
#define WINDOW_TITLE "Asteroids"
#define WIDTH_CENTER (WIDTH*1.0/2)
#define HEIGHT_CENTER (HEIGHT*1.0/2)

#define PLAYER_RADIUS 10
#define BULLET_RADIUS 1
#define BIG_ASTEROID_RADIUS 23
#define MEDIUM_ASTEROID_RADIUS 15
#define SMALL_ASTEROID_RADIUS 10

#define TEXTURE_SIZE 50
#define TEXTURE_CENTER TEXTURE_SIZE*1.0/2

#define ROTATION_UP 270

#define DIRECTION_LEFT -1
#define DIRECTION_RIGHT 1

#define TEXTURE_PATH (std::string)"./resources/"
#define TEXTURE_DEBUG_PATH (std::string)"../src/resources/"
#define loadFile(x, name) if(!x.loadFromFile(TEXTURE_PATH + name)) x.loadFromFile(TEXTURE_DEBUG_PATH + name)

#define TEXT_SCORE_SIZE 50
#define TEXT_MENU_SIZE 80
#define TEXT_CONTINUE_SIZE 30


struct position {
    double x;
    double y;
    double rotation = 0;
};

#endif
