#include <iostream>
#include "windows.h"
#include <vector>
#include <numeric>
#include <utility>
#include <math.h>

#ifndef PROJECT7_FIGURE_H
#define PROJECT7_FIGURE_H


class Point {
public:
    double _x;
    double _y;
    Point(double x = 0.0, double y = 0.0): _x(x),_y(y) {};
    ~Point() = default;

    int getX() { return _x; }
    int getY() { return _y; }
    void printPoint() {
        std::cout << "(" << _x << ";" << _y << ")" << std::endl;
    }

    void setPoint(double x, double y) {
        _x = x;
        _y = y;
    }
};


class Figure {
protected:
    std::string _type;
public:
    Figure(std::string type = "Figure0"): _type(type) {};
    virtual double perimeter();
    virtual double square();
    virtual void print();
    virtual ~Figure() = default;
};

class Polygon: public Figure {
protected:
    std::vector<Point> vertices;
public:
    Polygon(std::string type = "Polygon0"): Figure(type) {};
    virtual double perimeter() override;
    virtual double square() override;
    virtual void print() override;
    virtual ~Polygon() = default;
    virtual void setVertices(std::vector<Point>);
};

class Rectangle: public Polygon {
public:
    Rectangle(std::string type = "Rectangle0"): Polygon(type) {};
    virtual double square() override;
    virtual ~Rectangle() = default;
};

class Square: public Rectangle {
public:
    Square(std::string type = "Square0"): Rectangle(type) {};
    virtual double square() override;
    virtual ~Square() = default;
};

class Triangle: public Polygon {
public:
    Triangle(std::string type = "Triangle0"): Polygon(type) {};
    virtual double square() override;
    virtual ~Triangle() = default;
};

//class Ellipse: public Figure {
//protected:
//    Point _centre;
//    double _a;
//    double _b;
//public:
//    Ellipse(std::string type = "Ellipse0", Point centre = Point(0,0), double a = 1, double b = 1): Figure(type), _centre(centre), _a(a), _b(b) {};
//    virtual double perimeter();
//    virtual double square();
//    virtual void print();
//    virtual ~Ellipse() = default;
//    const double pi{3.14};
//};

#endif //PROJECT7_FIGURE_H