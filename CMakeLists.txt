cmake_minimum_required(VERSION 3.29)
project(game)

set(CMAKE_CXX_STANDARD 20)

add_executable(game main.cpp
        infrastructure/Screen.cpp
        infrastructure/Screen.h
        infrastructure/Keyboard.cpp
        infrastructure/Keyboard.h
        objects/Object.cpp
        objects/Object.h
        objects/Map.cpp
        objects/Map.h
        common/Point.h
        common/Camera.cpp
        common/Camera.h
        objects/Player.cpp
        objects/Player.h)

configure_file(rooms/room1.txt ${CMAKE_BINARY_DIR}/room1.txt COPYONLY)