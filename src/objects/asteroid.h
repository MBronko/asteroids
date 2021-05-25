#ifndef ASTEROIDS_ASTEROID_H
#define ASTEROIDS_ASTEROID_H

#include <iostream>
#include <vector>
#include <memory>
#include "SFML/Graphics.hpp"
#include "../common.h"
#include "entity.h"


class Asteroid : public Flying_entity {
public:
    Asteroid(position pos, position velocity);

    virtual std::vector<Asteroid*> create_new_objects() = 0;
//    virtual std::vector<std::shared_ptr<Asteroid>> create_new_objects() = 0;


};

class Big_asteroid : public Asteroid {
private:

public:
    Big_asteroid(position pos, position velocity);

    std::vector<Asteroid*> create_new_objects() override;
//    std::vector<std::shared_ptr<Asteroid>> create_new_objects() override;

//    void draw(sf::RenderWindow *win) override;
};

class Medium_asteroid : public Asteroid {
public:
    Medium_asteroid(position pos, position velocity);

    std::vector<Asteroid*> create_new_objects() override;
//    std::vector<std::shared_ptr<Asteroid>> create_new_objects() override;

//    void draw(sf::RenderWindow *win) override;
};

class Small_asteroid : public Asteroid {
private:

public:
    Small_asteroid(position pos, position velocity);

    std::vector<Asteroid*> create_new_objects() override;
//    std::vector<std::shared_ptr<Asteroid>> create_new_objects() override;
};

#endif
