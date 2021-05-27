#include "entity.h"
#include "../components/view.h"
#include "../utils.h"

bool Entity::out_of_bounds() const {
    double x = pos.x;
    double y = pos.y;

    return x < 0 || x > WIDTH || y < 0 || y > HEIGHT;
}

void Entity::draw(sf::RenderWindow *win) {
    sprite.setOrigin(TEXTURE_CENTER, TEXTURE_CENTER);
    sprite.setPosition((float) pos.x, (float) pos.y);
    sprite.setRotation((float) rotation);

    win->draw(sprite);
}

void Flying_entity::move() {
    pos.x += velocity.x;
    pos.y += velocity.y;
    rotation += shorten_rotation(rotation_span);
}

Flying_entity::Flying_entity() {
    rotation = (int) (rand() % 360);
}

Bullet::Bullet(position pos, position velocity) {
    this->pos = pos;
    this->velocity = velocity;
    this->radius = BULLET_RADIUS;

    sprite.setTexture(textures[4]);
}