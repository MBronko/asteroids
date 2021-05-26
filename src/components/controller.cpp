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
        if (win->hasFocus()) {
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
        }
        model->move_all();
        std::cout << model->get_player().get_x() << " " << model->get_player().get_y() << " "
                  << model->get_player().rotation << std::endl;
        view->draw();
    }
}

//
//Model model = Model();
//View view(model);
////    for (int i = 0; i < 30; i++) {
////        model.create_asteroid();
////    }
//
//
////    for (int i = 0; i < HEIGHT; i+=2*BIG_ASTEROID_RADIUS) {
////        for (int j = 0; j < WIDTH; j+=2*BIG_ASTEROID_RADIUS) {
////            Asteroid *aste = new Big_asteroid({(double)i, (double)j}, {0, 0});
////            aste->rotation_span = 0;
////            aste->rotation = 0;
////            model.get_asteroids().push_back(aste);
////        }
////    }
//
//int counter = 0;
//while (view->win->isOpen()) {
//sf::Event event{};
//while (view->win->pollEvent(event)){
//
//}
//view->draw();
//
////        model.move_all();
//model.player_move();
//
////        mod(5, model.create_asteroid());
//mod(15, model.player_rotate(DIRECTION_RIGHT));
////        mod(10, model.player_shoot());
//
////        std::cout << model.get_asteroids().size() << " " << model.get_bullets().size() << std::endl;
//std::cout << model.get_player().get_x() << " " << model.get_player().get_y() << std::endl;
//counter++;
//}