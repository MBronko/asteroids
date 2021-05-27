#include "controller.h"
#include "../utils.h"

Controller::Controller(Model *model, View *view) : model(model), view(view) {
    win = view->win;
}

void Controller::run() {
    sf::Event event{};
    while (win->isOpen()) {
        model->player.invincible = std::max(0, model->player.invincible - 1);
        model->player.shoot_cooldown = std::max(0, model->player.shoot_cooldown - 1);
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
        }
        if (win->hasFocus() && model->game_state == RUNNING) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                model->player_accelerate();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                model->player_rotate(DIRECTION_LEFT);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                model->player_rotate(DIRECTION_RIGHT);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                model->player_shoot();
            }
        }
        modulo(frame_count, 50, model->create_asteroid()); //create asteroid every 50 frames

        model->move_all();

        view->draw();
    }
}