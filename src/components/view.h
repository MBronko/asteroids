#ifndef ASTEROIDS_VIEW_H
#define ASTEROIDS_VIEW_H

#include "SFML/Graphics.hpp"
#include "model.h"
#include "../objects/asteroid.h"

extern sf::Texture textures[5];

class View {
private:
    sf::Font font;
    sf::Text text_score;
    sf::Text text_menu;
    sf::Text text_continue;
    sf::Texture heart_texture;
    sf::Sprite heart_sprite;

    static void center_text(sf::Text &text, float width, float height);

public:
    sf::RenderWindow *win;
    Model *model;

    explicit View(Model *model);

    void draw();

    ~View();
};


#endif
