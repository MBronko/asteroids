#include <iostream>
#include "objects/entity.h"
#include "utils.h"
#include <ctime>
#include <cmath>

int main() {
    srand(time(nullptr));

    position test = {WIDTH_CENTER-4, HEIGHT_CENTER - 3};

//    for (int i = 0; i < 50; i++){
        position test2 = velocity_towards_center(test);

        std::cout << test2.x << " " << test2.y << std::endl;
//    }
    std::cout << std::atan(4.0/3) << " " << std::atan(-4.0/3) << " " << std::atan(4.0/-3) << " " << std::atan(-4.0/-3) << " " << std::endl;

    std::cout << std::endl << to_degree(std::atan(4.0/3));

    return 0;
}
