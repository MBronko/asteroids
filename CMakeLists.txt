cmake_minimum_required(VERSION 3.17)
project(asteroids)

set(CMAKE_CXX_STANDARD 14)

add_executable(asteroids main.cpp objects.cpp objects.h model.cpp model.h view.cpp view.h controller.cpp controller.h)