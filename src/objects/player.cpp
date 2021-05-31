#include "player.h"
#include <iostream>
#include <cmath>
#include "../utils.h"
#include "../components/view.h"

Player::Player() {
    radius = PLAYER_RADIUS;
    sprite.setTexture(textures[0]);

    reset();
}

void Player::move() {
    invincible = std::max(0, invincible - 1);
    shoot_cooldown = std::max(0, shoot_cooldown - 1);

    pos.x += velocity.x;
    pos.y += velocity.y;

    pos.x = pos.x > WIDTH ? WIDTH - pos.x : pos.x < 0 ? pos.x + WIDTH : pos.x;
    pos.y = pos.y > HEIGHT ? HEIGHT - pos.y : pos.y < 0 ? pos.y + HEIGHT : pos.y;
}

void Player::accelerate() {
    position accel = rotate_pos({PLAYER_ACCELERATION, 0}, pos.rotation);

    if (calculate_velocity({velocity.x + accel.x, velocity.y + accel.y}) > MAX_PLAYER_VELOCITY) {
        double vector_reduction = 1 - PLAYER_ACCELERATION /  calculate_velocity(velocity);

        velocity.x *= vector_reduction;
        velocity.y *= vector_reduction;
    }

    velocity.x += accel.x;
    velocity.y += accel.y;
}

void Player::rotate(int dir) {
    pos.rotation = shorten_rotation(pos.rotation + PLAYER_ROTATION_SPAN * dir);
}

void Player::shoot(std::vector<Bullet> &bullets) {
    if (shoot_cooldown == 0) {
        bullets.emplace_back(Bullet(pos, rotate_pos({BULLET_VELOCITY, 0}, pos.rotation)));
        shoot_cooldown = PLAYER_SHOOT_COOLDOWN;
    }
}

void Player::reset() {
    pos = {WIDTH_CENTER, HEIGHT_CENTER, ROTATION_UP};
    velocity = {0, 0};
    invincible = PLAYER_INVINCIBLE_TIME;
}

void Player::decelerate(double vel) {
    double x = velocity.x;
    double y = velocity.y;
    if (x == 0 && y == 0) return;

    position dec = rotate_pos({vel, 0}, shorten_rotation(to_degree(std::atan2(y, x))));

    if ((x - dec.x) * x > 0) {
        velocity.x -= dec.x;
    }

    if ((y - dec.y) * y > 0) {
        velocity.y -= dec.y;
    }
}
