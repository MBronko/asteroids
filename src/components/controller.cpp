#include "controller.h"

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
        }
        if (win->hasFocus() && model->get_game_state() == RUNNING) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                model->player_move();
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
        if (frame_count % 50 == 0 ){
            model->create_asteroid();
            std::cout << model->get_player().lives << std::endl;
        }
        model->get_player().invincible = std::max(0, model->get_player().invincible-1);
        model->move_all();
//        std::cout << model->get_player().get_x() << " " << model->get_player().get_y() << " "
//                  << model->get_player().rotation << std::endl;
        view->draw();
    }
}