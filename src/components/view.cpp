#include "view.h"
#include "../common.h"
#include "SFML/Graphics.hpp"

// im not proud of this
sf::Texture textures[5];


View::View(Model *model) : model(model) {
    win = new sf::RenderWindow();
    win->create(sf::VideoMode(WIDTH, HEIGHT), WINDOW_TITLE, sf::Style::Close | sf::Style::Titlebar);

    win->setVerticalSyncEnabled(true);
    win->setFramerateLimit(FRAMERATE_LIMIT);
}

void View::draw() const {
    win->clear();

    if (model->game_state == RUNNING && model->player.invincible / PLAYER_INVINCIBLE_BLINK_RATE % 2 == 0) {
        model->player.draw(win);
    }

    for (auto &asteroid : model->asteroids) {
        asteroid->draw(win);
    }

    for (auto &bullet : model->bullets) {
        bullet.draw(win);
    }
    win->display();
}

View::~View() {
    delete win;
}
