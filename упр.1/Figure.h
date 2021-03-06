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

    int getX() const { return _x; }
    int getY() const { return _y; }
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
    virtual double perimeter() const = 0;
    virtual double square() const = 0;
    virtual void print();
    virtual ~Figure() = default;
};

class Polygon: public Figure {
protected:
    std::vector<Point> vertices;
public:
    Polygon(std::string type = "Polygon0"): Figure(type) {};
    virtual double perimeter() const override;
    virtual void print() override;
    virtual ~Polygon() = default;
    virtual void setVertices(std::vector<Point>);
};

class Rectangle: public Polygon {
public:
    Rectangle(std::string type = "Rectangle0"): Polygon(type) {};
    virtual double square() const override;
    virtual ~Rectangle() = default;
};

class Square: public Rectangle {
public:
    Square(std::string type = "Square0"): Rectangle(type) {};
    virtual double square() const override;
    virtual ~Square() = default;
};

class Triangle: public Polygon {
public:
    Triangle(std::string type = "Triangle0"): Polygon(type) {};
    virtual double square() const override;
    virtual ~Triangle() = default;
};

class Ellipse: public Figure {
protected:
    Point _centre;
    double _a;
    double _b;
public:
    Ellipse(std::string type = "Ellipse0"): Figure(type) {};
    virtual double perimeter() const;
    virtual double square() const;
    virtual void print();
    virtual void setCab(Point centre, double a, double b);
    virtual ~Ellipse() = default;
    const double pi{3.14};
};

class Circle: public Ellipse {
protected:
    double _r;
public:
Circle(std::string type = "Circle0"): Ellipse(type) {};
virtual double perimeter() const;
virtual double square() const;
virtual void setCr(Point centre, double r);
virtual ~Circle() = default;
};
#endif //PROJECT7_FIGURE_H