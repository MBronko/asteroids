#include <iostream>
#include "objects/entity.h"
#include <ctime>
#include <cmath>
#include "components/model.h"
#include "components/view.h"
#include "components/controller.h"

int main() {
    srand(time(nullptr));

    std::string texture_filename[5] = {"player.png", "big_asteroid.png", "medium_asteroid.png", "small_asteroid.png",
                                       "bullet.png"};
    for (int i = 0; i < 5; ++i) {
        loadFile(textures[i], texture_filename[i]);
    }

    auto *model = new Model();
    View *view = new View(model);

    Controller controller(model, view);
    controller.run();

    delete model;
    delete view;
    return 0;
}
