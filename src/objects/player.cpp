#include "../common.h"
#include "../utils.h"
#include "player.h"

Player::Player(sf::Texture texture) {
    pos = {WIDTH_CENTER, HEIGHT_CENTER};
    rotation = ROTATION_UP;
    radius = PLAYER_RADIUS;

//    sf::Texture texture;
    sprite.setTexture(texture);
}

void Player::move() {
    position shift = rotate_pos({PLAYER_STEP, 0}, rotation);

    pos.x += shift.x;
    pos.y += shift.y;

    pos.x = stay_in_bounds(0, pos.x, WIDTH);
    pos.y = stay_in_bounds(0, pos.y, HEIGHT);
}

void Player::rotate(int dir) {
    rotation = shorten_rotation(rotation + ROTATION_SPAN * dir);
}

void Player::shoot(std::vector<Bullet> &bullets) {
    bullets.emplace_back(pos, rotate_pos({BULLET_VELOCITY, 0}, rotation));
}

void Player::draw(sf::RenderWindow *win) {
    sprite.setPosition(top_left_corner(pos));
    sprite.setRotation((float)rotation);

    win->draw(sprite);
}

Player::Player() = default;
