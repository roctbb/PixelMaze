#include "Map.h"
#include <fstream>
#include <iostream>
#include <stdexcept>

// Конструктор, который считывает карту из файла
Map::Map(const std::string &filename, Screen &screen, Keyboard &keyboard, Camera &camera): Object(Point(0, 0),
    screen, keyboard, camera) {
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Не удалось открыть файл: " + filename);
    }

    std::string line;
    while (std::getline(file, line)) {
        data.push_back(line);
    }

    file.close();

    camera.setMapHeight(data.size());
    camera.setMapWidth(data[0].size());
}


bool Map::canMoveTo(int x, int y) const {
    // Проверяем, не выходит ли позиция за пределы карты
    if (y < 0 || y >= static_cast<int>(data.size()) ||
        x < 0 || x >= static_cast<int>(data[y].size())) {
        return false; // За пределами карты
    }

    return data[y][x] == ' '; // Можно перейти, если символ — пробел
}

// Метод для вывода карты
void Map::draw() const {
    for (int i = 0; i < static_cast<int>(data.size()); i++) {
        for (int j = 0; j < static_cast<int>(data[i].size()); j++) {
            Point screenPoint = camera.apply(Point(j, i));
            screen.draw(screenPoint.x, screenPoint.y, data[i][j]);
        }
    }
}
