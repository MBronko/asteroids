#include "view.h"
#include "../common.h"
#include "SFML/Graphics.hpp"

// :weary: ill leave it at that at this moment
sf::Texture textures[5];


View::View(Model &model) : model(model) {
    win = new sf::RenderWindow();
    win->create(sf::VideoMode(WIDTH, HEIGHT), "Asteroids", sf::Style::Close | sf::Style::Titlebar);

    win->setVerticalSyncEnabled(false);
    win->setFramerateLimit(FRAMERATE_LIMIT);

}

void View::draw() {
    win->clear();

    model.get_player().draw(win);

    for (auto &asteroid : model.get_asteroids()) {
        asteroid->draw(win);
    }

    for (auto &bullet : model.get_bullets()) {
        bullet.draw(win);
    }

    win->display();
}

View::~View() {
    delete win;
}
