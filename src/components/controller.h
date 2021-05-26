#ifndef ASTEROIDS_CONTROLLER_H
#define ASTEROIDS_CONTROLLER_H

#include "SFML/Graphics.hpp"
#include "model.h"
#include "view.h"

class Controller {
private:
    Model *model;
    View *view;
    sf::RenderWindow *win;
    uint64_t frame_count = 0;


public:
    Controller(Model *model, View *view);

    void run();

};


#endif
