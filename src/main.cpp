#include <iostream>
#include "objects/entity.h"
#include "utils.h"
#include <ctime>
#include <cmath>
#include "components/model.h"
#include "components/view.h"

int main() {
    srand(time(nullptr));

    textures[0].loadFromFile(TEXTURE_PATH + "player.png");
//    textures[0].loadFromFile(TEXTURE_PATH + "debug.png");
    textures[1].loadFromFile(TEXTURE_PATH + "big_asteroid.png");
    textures[2].loadFromFile(TEXTURE_PATH + "medium_asteroid.png");
    textures[3].loadFromFile(TEXTURE_PATH + "small_asteroid.png");
    textures[4].loadFromFile(TEXTURE_PATH + "bullet.png");

    Model model = Model();
    for (int i = 0; i < 30; i++) {
        model.create_asteroid();
//        model.player_shoot();
    }

    View view(model);

    int counter = 0;
    while (counter < INT32_MAX) {
        view.draw();

        model.move_all();
//        model.player_move();

//        for (int i = 0; i < 20; ++i) {
//        }
        if (counter % 5 == 0) {
        model.create_asteroid();
        }

//        if (counter % 5 == 0) {
            model.player_rotate(DIRECTION_RIGHT);
//        }
//        if (counter % 10 == 0) {
//        for (int i = 0; i < 3; ++i) {
//            model.player_shoot();
//        }
//        }


        std::cout << model.get_asteroids().size() << " " << model.get_bullets().size() << std::endl;

        counter++;
    }

    return 0;
}
