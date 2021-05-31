#include "controller.h"
#include "../utils.h"

Controller::Controller(Model *model, View *view) : model(model), view(view) {
    win = view->win;
}

void Controller::run() {
    sf::Event event{};
    while (win->isOpen()) {
        frame_count++;

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
            modulo(frame_count, 50, model->create_asteroid()); //create asteroid every 50 frames
            if (win->hasFocus() && model->game_state == RUNNING) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                    model->player.rotate(DIRECTION_LEFT);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                    model->player.accelerate();
                    passive_decelerate = false;
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                    model->player.decelerate(PLAYER_ACTIVE_DECELERATION);
                    passive_decelerate = false;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                    model->player.rotate(DIRECTION_RIGHT);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                    model->player_shoot();
                }
            }
            model->move_all();
        }
        if (passive_decelerate) model->player.decelerate(PLAYER_PASSIVE_DECELERATION);

        view->draw();
    }
}