#ifndef PLAYER_H
#define PLAYER_H

#include "Object.h"
#include "Map.h"
#include <vector>

class Player : public Object {
private:
    std::vector<char> animationSteps; // Символы анимации игрока
    int currentAnimationStep;         // Текущий шаг анимации
    int animationCounter;             // Счетчик (замедление анимации)
    Map& room;

    // Метод для обновления символа игрока
    void updateAnimation();

    // Метод для центрирования камеры относительно игрока
    void updateCamera();

public:
    Player(Point startPosition, Screen &screen, Keyboard &keyboard, Camera &camera, Map& map);

    // Переопределяем метод обновления для обработки ввода
    void update() override;

    // Переопределяем символ для отображения игрока
    char symbol() override;
};

#endif //PLAYER_H