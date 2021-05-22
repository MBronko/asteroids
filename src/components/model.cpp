#include "model.h"
#include "../utils.h"

Model::Model() {
    player = Player();
}

void Model::check_collides() {
    for (auto &asteroid : asteroids) {
        if (objects_overlap(player.get_pos(), player.get_radius(), asteroid.get_pos(), asteroid.get_radius())) {
            game_state = ENDED_LOSE;
        }
    }
    for (auto bullet = bullets.end(); bullet != bullets.begin(); bullet--) {
        if (bullet->out_of_bounds()) {
            bullets.erase(bullet);
            continue;
        }
        for (auto asteroid = asteroids.end(); asteroid != asteroids.begin(); asteroid--) {
            if (asteroid->out_of_bounds()) {
                asteroids.erase(asteroid);
                continue;
            }
            if (objects_overlap(bullet->get_pos(), bullet->get_radius(), asteroid->get_pos(), asteroid->get_radius())) {
                auto new_asteroids = asteroid->destroy();
                asteroids.erase(asteroid);
                asteroids.insert(asteroids.end(), new_asteroids.begin(), new_asteroids.end());
            }
        }
    }
}

void Model::move_all() {
    player.move();

    for (auto &asteroid : asteroids) {
        asteroid.move();
    }

    for (auto &bullet : bullets) {
        bullet.move();
    }

    check_collides();
}

std::vector<Bullet> &Model::get_bullets() {
    return bullets;
}

std::vector<Asteroid> &Model::get_asteroids() {
    return asteroids;
}

Player &Model::get_player() {
    return player;
}

GameState Model::get_game_state() {
    return game_state;
}



