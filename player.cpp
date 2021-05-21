#include "player.h"

Player::Player() {
    x = WIDTH_CENTER;
    y = HEIGHT_CENTER;
    rotation = ROTATION_UP;
    radius = PLAYER_RADIUS;
}

void Player::move() {

}

void Player::rotate(int dir) {
    rotation = shorten_rotation(rotation + ROTATION_SPAN * dir);
}

void Player::shoot(std::vector<bullet> &bullets) {

}

