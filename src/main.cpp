#include <iostream>
#include "objects/entity.h"
#include "utils.h"
#include <ctime>
#include <cmath>
#include "components/model.h"
#include "components/view.h"

#define mod(x, do) if(counter % x == 0){do;}
#define times(x, do) for(int i = 0; i < x; i++){do;}

int main() {
    srand(time(nullptr));

    textures[0].loadFromFile(TEXTURE_PATH + "player.png");
//    textures[0].loadFromFile(TEXTURE_PATH + "debug.png");
    textures[1].loadFromFile(TEXTURE_PATH + "big_asteroid.png");
    textures[2].loadFromFile(TEXTURE_PATH + "medium_asteroid.png");
    textures[3].loadFromFile(TEXTURE_PATH + "small_asteroid.png");
    textures[4].loadFromFile(TEXTURE_PATH + "bullet.png");

    Model model = Model();
//    for (int i = 0; i < 30; i++) {
//        model.create_asteroid();
//    }

    View view(model);

//    for (int i = 0; i < HEIGHT; i+=2*BIG_ASTEROID_RADIUS) {
//        for (int j = 0; j < WIDTH; j+=2*BIG_ASTEROID_RADIUS) {
//            Asteroid *aste = new Big_asteroid({(double)i, (double)j}, {0, 0});
//            aste->rotation_span = 0;
//            aste->rotation = 0;
//            model.get_asteroids().push_back(aste);
//        }
//    }

    int counter = 0;
    while (view.win->isOpen()) {
        sf::Event event{};
        while (view.win->pollEvent(event)){

        }
        view.draw();

//        model.move_all();
        model.player_move();

//        mod(5, model.create_asteroid());
        mod(15, model.player_rotate(DIRECTION_RIGHT));
//        mod(10, model.player_shoot());

//        std::cout << model.get_asteroids().size() << " " << model.get_bullets().size() << std::endl;
        std::cout << model.get_player().get_x() << " " << model.get_player().get_y() << std::endl;
        counter++;
    }

    return 0;
}
