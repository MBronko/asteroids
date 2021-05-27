#include <iostream>
#include "objects/entity.h"
#include "utils.h"
#include <ctime>
#include <cmath>
#include "components/model.h"
#include "components/view.h"
#include "components/controller.h"

int main() {
    srand(time(nullptr));

    textures[0].loadFromFile(TEXTURE_PATH + "player.png");
//    textures[0].loadFromFile(TEXTURE_PATH + "debug.png");
    textures[1].loadFromFile(TEXTURE_PATH + "big_asteroid.png");
    textures[2].loadFromFile(TEXTURE_PATH + "medium_asteroid.png");
    textures[3].loadFromFile(TEXTURE_PATH + "small_asteroid.png");
    textures[4].loadFromFile(TEXTURE_PATH + "bullet.png");

    auto *model = new Model();
    View *view = new View(model);

    Controller controller(model, view);
    controller.run();

    delete model;
    delete view;
    return 0;
}
