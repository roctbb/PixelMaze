#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <unordered_set>

class Keyboard {
private:
    std::unordered_set<char> pressedKeys; // Набор нажатых клавиш
    bool initialized; // Флаг для состояния клавиатуры

    // Переключение режима терминала
    void enableRawMode();
    void disableRawMode();

public:
    // Конструктор и деструктор
    Keyboard();
    ~Keyboard();

    // Обновляет внутреннее состояние нажатых клавиш
    void refresh();

    // Проверяет, была ли нажата клавиша
    bool isPressed(char key) const;
};

#endif // KEYBOARD_H