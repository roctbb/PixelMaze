#ifndef SCREEN_H
#define SCREEN_H

#include <vector>
#include <string>
#include <iostream>

// Класс для рисования на консоли
class Screen {
private:
    int width, height;
    std::vector<std::vector<char>> buffer;
    char defaultChar;

    // Скрывает курсор
    void hideCursor() const;

    // Показывает курсор
    void showCursor() const;

public:
    // Конструктор и деструктор
    Screen(int w, int h, char defaultChar = ' ');
    ~Screen();

    // Очищает буфер
    void clear();

    // Рисует символ в заданной позиции
    void draw(int x, int y, char c);

    // Отображает экран из буфера
    void render() const;

    // Получает ширину экрана
    int getWidth() const { return width; }

    // Получает высоту экрана
    int getHeight() const { return height; }
};

#endif // SCREEN_H