#include <iostream>
#include "Figure.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);

    class Rectangle rect("Rectangle1");
    int n{4};
    std::vector<Point> points;
    std::cout << "Введите координаты вершин прямоугольника:" << std::endl;
    double tmpx{0}, tmpy{0};
    for( int i = 0; i < n; ++i) {
        std::cout << " x:";
        std::cin >> tmpx;
        std::cout << " y:";
        std::cin >> tmpy;
        points.push_back(Point(tmpx, tmpy));
    }
    rect.setVertices(points);
    rect.print();

    class Square square("square1");
    points.clear();
    std::cout << "Введите координаты вершин квадрата:" << std::endl;
    tmpx = 0, tmpy = 0;
    for( int i = 0; i < 4; ++i) {
        std::cout << " x:";
        std::cin >> tmpx;
        std::cout << " y:";
        std::cin >> tmpy;
        points.push_back(Point(tmpx, tmpy));
    }
    square.setVertices(points);
    square.print();

    class Triangle trig("Triangle1");
    n = 3;
    points.clear();
    std::cout << "Введите координаты вершин треугольника:" << std::endl;
    tmpx = 0, tmpy = 0;
    for( int i = 0; i < n; ++i) {
        std::cout << " x:";
        std::cin >> tmpx;
        std::cout << " y:";
        std::cin >> tmpy;
        points.push_back(Point(tmpx, tmpy));
    }
    trig.setVertices(points);
    trig.print();

    return 0;
}


