#include "Screen.h"
#include <cstdlib> // Для system("clear")
#include <iostream>

// Конструктор: инициализирует буфер и отключает курсор
Screen::Screen(int w, int h, char defaultChar)
    : width(w), height(h), defaultChar(defaultChar) {
    clear();
    hideCursor(); // Скрываем курсор
}

// Деструктор: включает курсор обратно
Screen::~Screen() {
    showCursor();
}

// Отключение курсора
void Screen::hideCursor() const {
    std::cout << "\033[?25l"; // Последовательность ANSI для скрытия курсора
    std::cout.flush();
}

// Включение курсора
void Screen::showCursor() const {
    std::cout << "\033[?25h"; // Последовательность ANSI для отображения курсора
    std::cout.flush();
}

// Очистка буфера (заполнение символами по умолчанию)
void Screen::clear() {
    buffer = std::vector<std::vector<char>>(height, std::vector<char>(width, defaultChar));
}

// Рисование символа в указанных координатах
void Screen::draw(int x, int y, char c) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        buffer[y][x] = c;
    }
}

// Отображение содержимого буфера на экране
void Screen::render() const {
    std::cout << "\033[H"; // Перемещение курсора в верхний левый угол
    for (const auto &row : buffer) {
        for (char c : row) {
            std::cout << c;
        }
        std::cout << '\n';
    }
    std::cout.flush(); // Принудительный вывод
}