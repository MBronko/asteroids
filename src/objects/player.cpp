#include "player.h"
#include "../utils.h"
#include "../components/view.h"

Player::Player() {
    radius = PLAYER_RADIUS;
    sprite.setTexture(textures[0]);

    reset();
}

void Player::move() {
    position shift = rotate_pos({PLAYER_STEP, 0}, rotation);

    pos.x += shift.x;
    pos.y += shift.y;

    pos.x = pos.x > WIDTH ? WIDTH - pos.x : pos.x < 0 ? pos.x + WIDTH : pos.x;
    pos.y = pos.y > HEIGHT ? HEIGHT - pos.y : pos.y < 0 ? pos.y + HEIGHT : pos.y;
}

void Player::rotate(int dir) {
    rotation = shorten_rotation(rotation + PLAYER_ROTATION_SPAN * dir);
}

void Player::shoot(std::vector<Bullet> &bullets) {
    if (shoot_cooldown == 0){
        bullets.emplace_back(Bullet(pos, rotate_pos({BULLET_VELOCITY, 0}, rotation)));
        shoot_cooldown = PLAYER_SHOOT_COOLDOWN;
    }
}

void Player::reset() {
    pos = {WIDTH_CENTER, HEIGHT_CENTER};
    rotation = ROTATION_UP;
    invincible = PLAYER_INVINCIBLE_TIME;
}
