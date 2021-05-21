#include "model.h"

model::model() {
    player = Player();
//    bullets =
}

void model::check_collides() {

}

void model::move_all() {
    player.move();

    for (auto asteroid : asteroids) {
        asteroid.move();
    }

    for (auto bullet : bullets) {
        bullet.move();
    }

    check_collides();
}

std::vector<bullet> &model::get_bullets() {
    return bullets;
}

std::vector<flying_object> &model::get_asteroids() {
    return asteroids;
}

Player &model::get_player() {
    return player;
}

GameState model::get_game_state() {
    return game_state;
}



