#include "model.h"
#include "../utils.h"
#include <algorithm>
#include <memory>
#include <vector>

Model::Model() {
    player = Player();
}

void Model::check_collisions(double delta_time) {
    if (game_state == RUNNING && player.invincible == 0) {
        for (auto &asteroid : asteroids) {
            if (objects_overlap(player.pos, player.radius, asteroid->pos, asteroid->radius)) {
                if (lives == 0) {
                    game_state = LOST;
//                } else {
//                    player.reset();
//                    lives--;
                }
            }
        }
    }

    asteroids.erase(std::remove_if(asteroids.begin(), asteroids.end(),
                                   [](std::shared_ptr<Asteroid> &o) { return o->out_of_bounds(); }),
                    asteroids.end());

    bullets.erase(std::remove_if(bullets.begin(), bullets.end(), [](Bullet &o) { return o.out_of_bounds(); }),
                  bullets.end());

    for (auto bullet = bullets.begin(); bullet != bullets.end();) {
        bool inc = true;
        for (auto asteroid = asteroids.begin(); asteroid != asteroids.end();) {
            if (objects_overlap(bullet->pos, bullet->radius, (*asteroid)->pos,
                                (*asteroid)->radius)) {
                auto new_asteroids = (*asteroid)->create_new_objects(delta_time);
                score += (*asteroid)->points;
                asteroids.erase(asteroid);
                asteroids.insert(asteroids.end(), new_asteroids.begin(), new_asteroids.end());
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

void Model::move_all(double delta_time) {
    player.move(delta_time);

    for (auto &asteroid : asteroids) {
        asteroid->move(delta_time);
    }

    for (auto &bullet : bullets) {
        bullet.move(delta_time);
    }
}

void Model::player_shoot() {
    player.shoot(bullets);
}

void Model::create_asteroid() {
    double new_x = random_range(0, 2 * SPAWN_AREA_SIZE);
    new_x = new_x < SPAWN_AREA_SIZE ? new_x : new_x + (WIDTH - 2 * SPAWN_AREA_SIZE);
    double new_y = random_range(0, 2 * SPAWN_AREA_SIZE);
    new_y = new_y < SPAWN_AREA_SIZE ? new_y : new_y + (HEIGHT - 2 * SPAWN_AREA_SIZE);

    position new_pos = {new_x, new_y};
    position new_vel = velocity_towards_center(new_pos);

    std::shared_ptr<Asteroid> new_asteroid;
    switch (rand() % 3) {
        case 0:
            new_asteroid = std::make_shared<Small_asteroid>(Small_asteroid(new_pos, new_vel));
            break;
        case 1:
            new_asteroid = std::make_shared<Medium_asteroid>(Medium_asteroid(new_pos, new_vel));
            break;
        default:
            new_asteroid = std::make_shared<Big_asteroid>(Big_asteroid(new_pos, new_vel));
            break;
    }
    asteroids.push_back(new_asteroid);
}