#include "model.h"
#include "../utils.h"
#include <iostream>
#include <algorithm>
#include <memory>
#include <vector>

Model::Model() {
    player = Player();
}

void Model::check_collides() {
//    for (auto &asteroid : asteroids) {
//        if (objects_overlap(player.get_pos(), player.get_radius(), asteroid->get_pos(), asteroid->get_radius())) {
//            game_state = ENDED_LOSE;
//            return;
//        }
//    }

    asteroids.erase(std::remove_if(asteroids.begin(), asteroids.end(), [](Asteroid *o) { return o->out_of_bounds(); }),
                    asteroids.end());

    bullets.erase(std::remove_if(bullets.begin(), bullets.end(), [](Bullet &o) { return o.out_of_bounds(); }),
                  bullets.end());


//    for (auto asteroid = asteroids.begin(); asteroid != asteroids.end();) {
//        if ((*asteroid)->out_of_bounds()) {
//            asteroid = asteroids.erase(asteroid);
//        } else {
//            asteroid++;
//        }
//    }
//    for (auto bullet = bullets.begin(); bullet != bullets.end();) {
//        if (bullet->out_of_bounds()) {
//            bullet = bullets.erase(bullet);
//        } else {
//            bullet++;
//        }
//    }

    for (auto bullet = bullets.begin(); bullet != bullets.end();) {
        bool inc = true;
        for (auto asteroid = asteroids.begin(); asteroid != asteroids.end();) {
            if (objects_overlap(bullet->get_pos(), bullet->get_radius(), (*asteroid)->get_pos(),
                                (*asteroid)->get_radius())) {
                auto new_asteroids = (*asteroid)->create_new_objects();
                asteroids.insert(asteroids.end(), new_asteroids.begin(), new_asteroids.end());
                asteroids.erase(asteroid);
                bullet = bullets.erase(bullet);
                inc = false;
                break;
            } else {
                asteroid++;
            }
        }
        if (inc) {
            bullet++;
        }
    }
}

void Model::move_all() {
    for (auto &asteroid : asteroids) {
        asteroid->move();
    }

    for (auto &bullet : bullets) {
        bullet.move();
    }

    check_collides();
}

void Model::player_move() {
    player.move();
}

void Model::player_shoot() {
    player.shoot(bullets);
}

void Model::player_rotate(int rot) {
    player.rotate(rot);
}

void Model::create_asteroid() {
    double new_x = random_range(0, 2 * SPAWN_AREA_SIZE);
    new_x = new_x < SPAWN_AREA_SIZE ? new_x : new_x + (WIDTH - 2 * SPAWN_AREA_SIZE);
    double new_y = random_range(0, 2 * SPAWN_AREA_SIZE);
    new_y = new_y < SPAWN_AREA_SIZE ? new_y : new_y + (HEIGHT - 2 * SPAWN_AREA_SIZE);

    position new_pos = {new_x, new_y};

    position new_vel = velocity_towards_center(new_pos);

    Asteroid *new_asteroid;
//    std::shared_ptr<Asteroid> new_asteroid;
    switch (random() % 3) {
        case 0:
//            new_asteroid = std::make_shared<Small_asteroid>(Small_asteroid(new_pos, new_vel));
            new_asteroid = new Small_asteroid(new_pos, new_vel);
            break;
        case 1:
            new_asteroid = new Medium_asteroid(new_pos, new_vel);
            break;
        default:
            new_asteroid = new Big_asteroid(new_pos, new_vel);
            break;
    }
    asteroids.push_back(new_asteroid);
}


std::vector<Bullet> &Model::get_bullets() {
    return bullets;
}

std::vector<Asteroid *> &Model::get_asteroids() {
//    std::vector<std::shared_ptr<Asteroid>> &Model::get_asteroids() {
    return asteroids;
}

Player &Model::get_player() {
    return player;
}

GameState Model::get_game_state() {
    return game_state;
}

