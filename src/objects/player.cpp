#include "../common.h"
#include "player.h"
#include "../utils.h"

Player::Player() {
    pos = {WIDTH_CENTER, HEIGHT_CENTER};
    rotation = ROTATION_UP;
    radius = PLAYER_RADIUS;
}

void Player::move() {
    position shift = rotate_pos({PLAYER_STEP, 0});

    pos.x += shift.x;
    pos.y += shift.y;

    pos.x = stay_in_bounds(0, pos.x, WIDTH);
    pos.y = stay_in_bounds(0, pos.y, HEIGHT);
}

void Player::rotate(int dir) {
    rotation = shorten_rotation(rotation + ROTATION_SPAN * dir);
}

void Player::shoot(std::vector<Bullet> &bullets) {
    bullets.emplace_back(pos, rotate_pos({BULLET_VELOCITY, 0}));
}
