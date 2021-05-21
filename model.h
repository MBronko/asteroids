#ifndef ASTEROIDS_MODEL_H
#define ASTEROIDS_MODEL_H

#include <iostream>
#include <vector>
#include "player.h"

enum GameState {
    MENU, RUNNING, ENDED_LOSE, ENDED_WIN
};

class model {
private:
    GameState game_state = MENU;
    int score = 0;
    Player player;
    std::vector<bullet> bullets = {};
    std::vector<flying_object> asteroids = {};


public:
    model();

    void check_collides();

    void move_all();

    std::vector<bullet> &get_bullets();

    std::vector<flying_object> &get_asteroids();

    Player &get_player();

    GameState get_game_state();
};


#endif
