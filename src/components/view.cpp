#include "view.h"
#include "../common.h"
#include "SFML/Graphics.hpp"

// im not proud of this
sf::Texture textures[5];

void View::center_text(sf::Text &text, float width, float height) {
    sf::FloatRect bounds = text.getLocalBounds();
    text.setPosition(width - bounds.width / 2, height - bounds.height / 2);
}


View::View(Model *model) : model(model) {
    win = new sf::RenderWindow();
    win->create(sf::VideoMode(WIDTH, HEIGHT), WINDOW_TITLE, sf::Style::Close | sf::Style::Titlebar);

    win->setVerticalSyncEnabled(true);
    win->setFramerateLimit(FRAMERATE_LIMIT);

    loadFile(font, "Pixellettersfull-BnJ5.ttf");

    text_score.setFont(font);
    text_score.setCharacterSize(TEXT_SCORE_SIZE);
    text_score.setFillColor(sf::Color::White);

    text_menu.setFont(font);
    text_menu.setCharacterSize(TEXT_MENU_SIZE);
    text_menu.setFillColor(sf::Color::White);

    text_continue.setFont(font);
    text_continue.setCharacterSize(TEXT_CONTINUE_SIZE);
    text_continue.setFillColor(sf::Color::White);
    text_continue.setString("Press enter to continue");
    center_text(text_continue, WIDTH_CENTER, HEIGHT_CENTER + 60);

    loadFile(heart_texture, "heart.png");
    heart_sprite.setTexture(heart_texture);
    heart_sprite.setScale(2.0f, 2.0f);
}

void View::draw() {
    win->clear();

    for (auto &asteroid : model->asteroids) {
        asteroid->draw(win);
    }

    for (auto &bullet : model->bullets) {
        bullet.draw(win);
    }

    text_score.setString("Score: " + std::to_string(model->score));
    switch (model->game_state) {
        case RUNNING:
            if (model->player.invincible / PLAYER_INVINCIBLE_BLINK_RATE % 2 == 0 || model->is_paused) {
                model->player.draw(win);
            }
            for (int i = 0; i < model->lives; ++i) {
                heart_sprite.setPosition(40.0f * (float) i, 40.0f);
                win->draw(heart_sprite);
            }
            text_score.setPosition(30, 0);

            if (model->is_paused) {
                text_menu.setString("PAUSE");
                center_text(text_menu, WIDTH_CENTER, HEIGHT_CENTER - 40);
                win->draw(text_menu);
            }

            win->draw(text_score);
            break;
        case LOST:
            text_menu.setString("GAME OVER");
            center_text(text_menu, WIDTH_CENTER, HEIGHT_CENTER - 40);
            center_text(text_score, WIDTH_CENTER, HEIGHT_CENTER - 110);

            win->draw(text_score);
            win->draw(text_menu);
            win->draw(text_continue);
            break;
        case MENU:
            text_menu.setString("NEW GAME");
            center_text(text_menu, WIDTH_CENTER, HEIGHT_CENTER - 40);

            win->draw(text_menu);
            win->draw(text_continue);
            break;
    }

    win->display();
}

View::~View() {
    delete win;
}
