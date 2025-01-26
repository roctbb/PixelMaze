#include "Keyboard.h"
#include <termios.h> // Для работы с режимами терминала
#include <unistd.h>  // Для функции read()
#include <iostream>  // Для ввода/вывода

static struct termios orig_termios; // Сохранение исходного режима терминала

// Включение сырого режима терминала
void Keyboard::enableRawMode() {
    struct termios raw;

    // Берём текущие настройки терминала
    tcgetattr(STDIN_FILENO, &orig_termios);
    raw = orig_termios;

    // Отключаем канонический режим, эхо и задержки
    raw.c_lflag &= ~(ECHO | ICANON | ISIG);
    raw.c_cc[VMIN] = 0;  // Минимальное количество символов для ввода
    raw.c_cc[VTIME] = 1; // Таймаут ввода (в десятых долях секунды)

    // Применяем настройки
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

// Восстановление исходного режима терминала
void Keyboard::disableRawMode() {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

// Конструктор: включает сырой режим терминала
Keyboard::Keyboard() : initialized(false) {
    enableRawMode();
    initialized = true;
}

// Деструктор: восстанавливает исходный режим терминала
Keyboard::~Keyboard() {
    if (initialized) {
        disableRawMode();
    }
}

// Обновляет состояние клавиш
void Keyboard::refresh() {
    pressedKeys.clear();

    char buf[1];
    while (read(STDIN_FILENO, buf, 1) == 1) { // Считываем символы из ввода
        pressedKeys.insert(buf[0]);
    }
}

// Проверяет, была ли нажата клавиша
bool Keyboard::isPressed(char key) const {
    return pressedKeys.find(key) != pressedKeys.end();
}