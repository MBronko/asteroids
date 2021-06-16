#include "controller.h"
#include "../utils.h"

Controller::Controller(Model *model, View *view) : model(model), view(view) {
    win = view->win;
}

void Controller::run() {
    sf::Event event{};
    sf::Clock clock;
    double new_asteroid_time = 0;
    while (win->isOpen()) {
        double delta_time = clock.restart().asSeconds();
        frame_count++;
        new_asteroid_time += delta_time;

        while (win->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                win->close();
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                switch (model->game_state) {
                    case MENU:
                        model->player.reset();
                        model->lives = PLAYER_INITIAL_LIVES;
                        model->score = 0;
                        model->game_state = RUNNING;
                        break;
                    case LOST:
                        model->game_state = MENU;
                        break;
                    default:
                        break;
                }
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P) {
                model->is_paused = !model->is_paused;
            }
        }

        bool passive_decelerate = true;
        if (!model->is_paused) {
            if (new_asteroid_time >= NEW_ASTEROID_SPAWN_RATE){
                model->create_asteroid();
                new_asteroid_time = 0;
            }
            if (win->hasFocus() && model->game_state == RUNNING) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                    model->player.accelerate(delta_time);
                    passive_decelerate = false;
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                    model->player.decelerate(delta_time, PLAYER_ACTIVE_DECELERATION);
                    passive_decelerate = false;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                    model->player.rotate(delta_time, DIRECTION_LEFT);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                    model->player.rotate(delta_time, DIRECTION_RIGHT);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                    model->player_shoot();
                }
            }
            model->move_all(delta_time);
            model->check_collisions(delta_time);
        }
        if (passive_decelerate) model->player.decelerate(delta_time, PLAYER_PASSIVE_DECELERATION);

        view->draw();
    }
}