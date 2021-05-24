cmake_minimum_required(VERSION 3.17)
project(asteroids)

set(CMAKE_CXX_STANDARD 14)

add_executable(asteroids src/main.cpp src/objects/entity.cpp src/objects/entity.h src/components/model.cpp src/components/model.h src/components/view.cpp src/components/view.h src/components/controller.cpp src/components/controller.h src/objects/player.cpp src/objects/player.h src/common.h src/utils.cpp src/utils.h src/objects/asteroid.cpp src/objects/asteroid.h)

if (UNIX)
    set ( CMAKE_MODULES_PATH "/usr/share/SFML/cmake/Modules" ${CMAKE_MODULE_PATH})
endif(UNIX)

if (WIN32)
    set( SFML_STATIC_LIBRARIES TRUE )

    set ( SFML_DIR "C:/cpp/SFML-2.5.1/lib/cmake/SFML/")
endif(WIN32)

find_package(SFML 2 COMPONENTS graphics audio REQUIRED)

target_link_libraries(asteroids sfml-graphics sfml-audio)

#set(CMAKE_CXX_STANDARD_LIBRARIES "-static-libgcc -static-libstdc++")