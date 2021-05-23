#include <iostream>
#include "objects/entity.h"
#include "utils.h"
#include <ctime>

int main() {
    srand(time(nullptr));

    std::cout << to_radians(90) << std::endl;

    return 0;
}
