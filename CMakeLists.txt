cmake_minimum_required(VERSION 3.17)
project(asteroids)

set(CMAKE_CXX_STANDARD 14)

add_executable(asteroids src/main.cpp src/objects/objects.cpp src/objects/objects.h src/components/model.cpp src/components/model.h src/components/view.cpp src/components/view.h src/components/controller.cpp src/components/controller.h src/objects/player.cpp src/objects/player.h src/common.h src/utils.cpp src/utils.h src/objects/asteroid.cpp src/objects/asteroid.h)