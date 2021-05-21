#include "asteroid.h"
#include "ctime"
#include <random>

asteroid::asteroid(double x, double y, double x_vel, double y_vel) {
    this->x = x;
    this->y = y;
    this->x_vel = x_vel;
    this->y_vel = y_vel;
    this->rotation = (int) (random() % 360);
}

big_asteroid::big_asteroid(double x, double y, double x_vel, double y_vel) : asteroid(x, y, x_vel, y_vel) {
    this->radius = BIG_ASTEROID_RADIUS;
}

void big_asteroid::move() {

}

std::vector<asteroid> big_asteroid::destroy() {
    std::vector<asteroid> res = {};
    return res;
}

medium_asteroid::medium_asteroid(double x, double y, double x_vel, double y_vel) : asteroid(x, y, x_vel, y_vel) {
    this->radius = MEDIUM_ASTEROID_RADIUS;
}

void medium_asteroid::move() {

}

std::vector<asteroid> medium_asteroid::destroy() {
    return std::vector<asteroid>();
}

small_asteroid::small_asteroid(double x, double y, double x_vel, double y_vel) : asteroid(x, y, x_vel, y_vel) {
    this->radius = SMALL_ASTEROID_RADIUS;
}


void small_asteroid::move() {

}

std::vector<asteroid> small_asteroid::destroy() {
    return std::vector<asteroid>();
}
