#ifndef ASTEROIDS_MODEL_H
#define ASTEROIDS_MODEL_H

#include <iostream>
#include <memory>
#include <vector>
#include "../objects/player.h"
#include "../objects/asteroid.h"

enum GameState {
    MENU, RUNNING, ENDED_LOSE, ENDED_WIN
};

class Model {
private:
    GameState game_state = RUNNING;
    int score = 0;
    Player player;
    std::vector<Bullet> bullets = {};

//    std::vector<std::shared_ptr<Asteroid>> asteroids = {};
    std::vector<Asteroid*> asteroids = {};


public:
    Model();

    void check_collides();

    void move_all();

    void player_move();

    void player_shoot();

    void player_rotate(int rot);

    void create_asteroid();

    std::vector<Bullet> &get_bullets();

//    std::vector<std::shared_ptr<Asteroid>> &get_asteroids();
    std::vector<Asteroid*> &get_asteroids();

    Player &get_player();

    GameState get_game_state();
};


#endif
