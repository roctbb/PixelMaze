#include <iostream>
#include <thread> // Для std::this_thread::sleep_for
#include <chrono> // Для std::chrono::milliseconds
#include "infrastructure/Screen.h"
#include "infrastructure/Keyboard.h"
#include "objects/Map.h"
#include "objects/Player.h"

int main() {
    Screen screen(40, 20); // Создаём экран размером 20x20
    Keyboard keyboard; // Инициализируем клавиатуру
    Camera camera(40, 20); // Создаём камеру

    camera.setMapWidth(50); // Устанавливаем размеры карты
    camera.setMapHeight(30);

    Map room("room1.txt", screen, keyboard, camera); // Загружаем карту

    Point startPosition(1, 1); // Начальная позиция игрока
    Player player(startPosition, screen, keyboard, camera, room); // Создаём игрока


    // Главный игровой цикл
    while (true) {
        keyboard.refresh(); // Обновляем состояние клавиш
        screen.clear(); // Очищаем экран
        room.draw(); // Отрисовываем карту

        player.update(); // Обновляем состояние игрока (перемещение и камера)
        player.draw(); // Рисуем игрока

        screen.render(); // Обновляем экран


        // Задержка, чтобы движение было плавным
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }

    return 0;
}
