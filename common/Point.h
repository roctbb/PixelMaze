#ifndef POINT_H
#define POINT_H

struct Point {
    int x; // Координата X
    int y; // Координата Y

    Point() : x(0), y(0) {}              // Конструктор по умолчанию
    Point(int x, int y) : x(x), y(y) {}  // Конструктор с параметрами
};

#endif // POINT_H