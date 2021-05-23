#include "model.h"
#include "../utils.h"

Model::Model() {
    player = Player();
}

void Model::check_collides() {
    for (auto &asteroid : asteroids) {
        if (objects_overlap(player.get_pos(), player.get_radius(), asteroid->get_pos(), asteroid->get_radius())) {
            game_state = ENDED_LOSE;
            return;
        }
    }
    for (auto bullet = bullets.end(); bullet != bullets.begin(); bullet--) {
        if (bullet->out_of_bounds()) {
            bullets.erase(bullet);
            continue;
        }
        for (auto asteroid = asteroids.end(); asteroid != asteroids.begin(); asteroid--) {
            if (asteroid->get()->out_of_bounds()) {
                asteroids.erase(asteroid);
                continue;
            }
            if (objects_overlap(bullet->get_pos(), bullet->get_radius(), asteroid->get()->get_pos(),
                                asteroid->get()->get_radius())) {
                auto new_asteroids = asteroid->get()->create_new_objects();
                asteroids.erase(asteroid);
                asteroids.insert(asteroids.end(), new_asteroids.begin(), new_asteroids.end());
            }
        }
    }
}

void Model::move_all() {
    player.move();

    for (auto &asteroid : asteroids) {
        asteroid->move();
    }

    for (auto &bullet : bullets) {
        bullet.move();
    }

    check_collides();
}

void Model::create_asteroid() {
    double new_x = random_range(0, 2*SPAWN_AREA_SIZE);
    new_x = new_x < SPAWN_AREA_SIZE ? new_x : new_x + (WIDTH - 2*SPAWN_AREA_SIZE);
    double new_y = random_range(0, 2*SPAWN_AREA_SIZE);
    new_y = new_y < SPAWN_AREA_SIZE ? new_y : new_y + (HEIGHT - 2*SPAWN_AREA_SIZE);

    position new_pos = {new_x, new_y};

    position new_vel = velocity_towards_center(new_pos);

    std::shared_ptr<Asteroid> new_asteroid;
    switch (random() % 3) {
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


std::vector<Bullet> &Model::get_bullets() {
    return bullets;
}

std::vector<std::shared_ptr<Asteroid>> &Model::get_asteroids() {
    return asteroids;
}

Player &Model::get_player() {
    return player;
}

GameState Model::get_game_state() {
    return game_state;
}


