#include "Camera.h"
#include <algorithm>

// Конструктор для настройки камеры и размеров карты
Camera::Camera(int viewWidth, int viewHeight)
    : width(viewWidth),
      height(viewHeight),
      mapHeight(0), mapWidth(0),
      topLeft(0, 0) {
}

// Установить положение камеры (верхний левый угол)
void Camera::setPosition(const Point &point) {
    topLeft.x = std::max(0, std::min(point.x, mapWidth - width));
    topLeft.y = std::max(0, std::min(point.y, mapHeight - height));
}

// Преобразовать глобальную координату в экранную
Point Camera::apply(const Point &globalPoint) const {
    if (isVisible(globalPoint)) {
        return Point(globalPoint.x - topLeft.x, globalPoint.y - topLeft.y);
    }
    // Если точка за пределами экрана, возвращаем "невалидные" координаты (-1, -1)
    return Point(-1, -1);
}

// Проверить, находится ли точка в области видимости
bool Camera::isVisible(const Point &globalPoint) const {
    return globalPoint.x >= topLeft.x && globalPoint.x < topLeft.x + width &&
           globalPoint.y >= topLeft.y && globalPoint.y < topLeft.y + height;
}

// Сдвиг камеры вправо
void Camera::right() {
    if (topLeft.x + width < mapWidth) {
        ++topLeft.x;
    }
}

// Сдвиг камеры влево
void Camera::left() {
    if (topLeft.x > 0) {
        --topLeft.x;
    }
}

// Сдвиг камеры вверх
void Camera::up() {
    if (topLeft.y > 0) {
        --topLeft.y;
    }
}

// Сдвиг камеры вниз
void Camera::down() {
    if (topLeft.y + height < mapHeight) {
        ++topLeft.y;
    }
}
