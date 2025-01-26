//
// Created by Rostislav Borodin on 26.01.2025.
//

#ifndef OBJECT_H
#define OBJECT_H

#include "../common/Camera.h"
#include "../common/Point.h"
#include "../infrastructure/Keyboard.h"
#include "../infrastructure/Screen.h"


class Object {
protected:
    Point position;
    Screen &screen;
    Keyboard &keyboard;
    Camera &camera;

public:
    Object(Point startPosition, Screen &screen, Keyboard &keyboard, Camera &camera)
        : position(startPosition), screen(screen), keyboard(keyboard), camera(camera) {
    }

    virtual ~Object() {
    };

    virtual void draw() {
        Point screenPoint = camera.apply(position);
        screen.draw(screenPoint.x, screenPoint.y, symbol());
    };

    virtual void update() {
    };

    virtual char symbol() {
        return ' ';
    }
};


#endif //OBJECT_H
