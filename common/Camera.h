#ifndef CAMERA_H
#define CAMERA_H

#include "Point.h"

class Camera {
private:
    Point topLeft; // Левый верхний угол камеры
    int width; // Ширина отображаемой области экрана
    int height; // Высота отображаемой области экрана
    int mapWidth; // Ширина глобальной карты
    int mapHeight; // Высота глобальной карты

public:
    // Конструктор для настройки камеры и размеров карты
    Camera(int viewWidth, int viewHeight);

    // Установить положение камеры (верхний левый угол)
    void setPosition(const Point &point); // Принимает Point

    // Получить текущую позицию верхнего левого угла камеры
    Point getTopLeft() const { return topLeft; }

    // Преобразовать глобальную координату в экранную
    Point apply(const Point &globalPoint) const;

    // Проверить, находится ли точка в области видимости
    bool isVisible(const Point &globalPoint) const;

    // Методы для сдвига камеры
    void right(); // Сдвиг камеры вправо
    void left(); // Сдвиг камеры влево
    void up(); // Сдвиг камеры вверх
    void down(); // Сдвиг камеры вниз

    // Геттеры и сеттеры для размеров
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    void setWidth(int viewWidth) { width = viewWidth; }
    void setHeight(int viewHeight) { height = viewHeight; }

    // Методы для изменения размеров карты
    int getMapWidth() const { return mapWidth; }
    int getMapHeight() const { return mapHeight; }
    void setMapWidth(int newMapWidth) { mapWidth = newMapWidth; }
    void setMapHeight(int newMapHeight) { mapHeight = newMapHeight; }
};

#endif // CAMERA_H
