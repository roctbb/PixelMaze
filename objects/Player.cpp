#include "Player.h"
#include "Map.h" // Для работы с методом canMoveTo()
#include <algorithm>

// Конструктор игрока
Player::Player(Point startPosition, Screen &screen, Keyboard &keyboard, Camera &camera, Map& room)
    : Object(startPosition, screen, keyboard, camera),
      animationSteps({'/', '-', '\\', '|'}), // Инициализация символов для анимации
      currentAnimationStep(0),
      animationCounter(0), room(room) {}

// Переопределение метода update
void Player::update() {
    // Обновляем анимацию
    updateAnimation();

    int newX = position.x;
    int newY = position.y;

    // Обработка передвижения игрока
    if (keyboard.isPressed('w')) {
        --newY;
    }
    if (keyboard.isPressed('s')) {
        ++newY;
    }
    if (keyboard.isPressed('a')) {
        --newX;
    }
    if (keyboard.isPressed('d')) {
        ++newX;
    }

    // Проверяем, можно ли перейти на новую клетку карты
    if (room.canMoveTo(newX, newY)) {
        position.x = newX;
        position.y = newY;
    }
    else {
        int y = 1;
    }

    // Обновляем положение камеры
    updateCamera();
}

// Метод для обновления символа анимации
void Player::updateAnimation() {
    ++animationCounter; // Увеличиваем счетчик

    // Если анимация должна обновиться (например, каждые 5 кадров)
    if (animationCounter >= 5) {
        animationCounter = 0;                       // Сбрасываем счетчик
        currentAnimationStep = (currentAnimationStep + 1) % animationSteps.size(); // Следующий шаг
    }
}

// Метод для обновления камеры
void Player::updateCamera() {
    Point cameraPos = camera.getTopLeft();

    // Центрируем камеру на игроке
    cameraPos.x = position.x - camera.getWidth() / 2;
    cameraPos.y = position.y - camera.getHeight() / 2;

    // Ограничиваем позицию камеры в пределах карты
    cameraPos.x = std::max(0, std::min(cameraPos.x, camera.getMapWidth() - camera.getWidth()));
    cameraPos.y = std::max(0, std::min(cameraPos.y, camera.getMapHeight() - camera.getHeight()));

    camera.setPosition(cameraPos); // Устанавливаем позицию камеры
}

// Переопределение метода для получения текущего символа игрока
char Player::symbol() {
    return animationSteps[currentAnimationStep]; // Возвращаем текущий символ анимации
}