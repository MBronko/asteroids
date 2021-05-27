#ifndef ASTEROIDS_MODEL_H
#define ASTEROIDS_MODEL_H

#include <iostream>
#include <memory>
#include <vector>
#include "../objects/player.h"
#include "../objects/asteroid.h"

enum GameState {
    MENU, RUNNING, LOST
};

class Model {
public:
    std::vector<std::shared_ptr<Asteroid>> asteroids = {};
    std::vector<Bullet> bullets = {};
    Player player;
    GameState game_state = RUNNING;
    int score = 0;

    Model();

    void check_collides();

    void move_all();

    void player_move();

    void player_shoot();

    void player_rotate(int rot);

    void create_asteroid();
};


#endif
