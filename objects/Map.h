#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>

#include "Object.h"
#include "../infrastructure/Screen.h"

class Map : public Object {
private:
    std::vector<std::string> data; // Вектор строк, представляющий карту

public:
    // Конструктор, который считывает карту из файла
    Map(const std::string &filename, Screen &screen, Keyboard &keyboard, Camera &camera);

    // Метод для проверки, можно ли перейти в ячейку (x, y)
    bool canMoveTo(int x, int y) const;

    // Метод для вывода карты
    void draw() const;
};

#endif // MAP_H
