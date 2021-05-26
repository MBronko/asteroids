#ifndef ASTEROIDS_VIEW_H
#define ASTEROIDS_VIEW_H

#include "SFML/Graphics.hpp"
#include "model.h"
#include "../objects/asteroid.h"

extern sf::Texture textures[5];

class View {

public:
    explicit View(Model *model);

    void draw() const;

    ~View();

    sf::RenderWindow *win;
    Model *model;
};


#endif
