#include "view.h"
#include "../common.h"
#include "SFML/Graphics.hpp"

View::View(Model &model) : model(model) {
//    win.create(sf::VideoMode(WIDTH, HEIGHT), "Asteroids", sf::Style::Close | sf::Style::Titlebar);
    win = new sf::RenderWindow();
    win->create(sf::VideoMode(WIDTH, HEIGHT), "Asteroids", sf::Style::Close | sf::Style::Titlebar);

    win->setVerticalSyncEnabled(false);
    win->setFramerateLimit(3);

}

void View::draw() {
    win->clear();

    model.get_player().draw(win);

    model.get_player().move();
    model.get_player().rotate(DIRECTION_RIGHT);

    win->display();
}

View::~View() {
    delete win;
}
