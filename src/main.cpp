#include <iostream>
#include "objects/entity.h"
#include "utils.h"
#include <ctime>
#include <cmath>
#include "components/model.h"
#include "components/view.h"

int main() {
    srand(time(nullptr));

    Model model = Model();

    View view(model);

    while (true) {
        view.draw();
    }

    return 0;
}
