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
    GameState game_state = MENU;
    int score = 0;
    int lives = 0;
    bool is_paused = false;

    Model();

    void check_collisions(double delta_time);

    void move_all(double delta_time);

    void player_shoot();

    void create_asteroid();
};


#endif
