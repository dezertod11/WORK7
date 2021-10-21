#include "Figure.h"


double Figure::perimeter() { return 0.0; };
double Figure::square() { return 0.0; };
void Figure::print() { std::cout << _type << std::endl; };


double Polygon::perimeter() {
    double p = 0;
    for (int i = 0; i < vertices.size(); ++i) {
        if (i == vertices.size() - 1) {
            p += std::sqrt(  (vertices[i].getX() - vertices[0].getX())*(vertices[i].getX() - vertices[0].getX()) + (vertices[i].getY() - vertices[0].getY())*(vertices[i].getY() - vertices[0].getY()) );
        }
        else {
            p += std::sqrt(  (vertices[i].getX() - vertices[i+1].getX())*(vertices[i].getX() - vertices[i+1].getX()) + (vertices[i].getY() - vertices[i+1].getY())*(vertices[i].getY() - vertices[i+1].getY()) );
        }
    }
    return p;
};
double Polygon::square() { return 0; };
void Polygon::print() {
    std::cout << _type << ":"<< std::endl;
    std::cout << "Вершины:"<< std::endl;
    for(auto & elem: vertices) {
        elem.printPoint();
    }
    std::cout << "Периметр = " << perimeter() << std::endl;
    std::cout << "Площадь = " << square() << std::endl;
}
void Polygon::setVertices(std::vector<Point> points) {
    for (auto point: points) {
        vertices.push_back(point);
    }
}

double Rectangle::square() {
    double s = 1;
    for (int i = 0; i < 2; ++i) {
        s *= std::sqrt(  (vertices[i].getX() - vertices[i+1].getX())*(vertices[i].getX() - vertices[i+1].getX()) + (vertices[i].getY() - vertices[i+1].getY())*(vertices[i].getY() - vertices[i+1].getY()) );
    }
    return s;
};

double Square::square() {
    double s{1};
    s *= std::sqrt(  (vertices[0].getX() - vertices[1].getX())*(vertices[0].getX() - vertices[1].getX()) + (vertices[0].getY() - vertices[1].getY())*(vertices[0].getY() - vertices[1].getY()) );
    s *=s;
    return s;
};

double Triangle::square() {
    double s{1};
    double p{perimeter()/2};
    s *= p;
    for (int i = 0; i < vertices.size(); ++i) {
        if (i == vertices.size() - 1) {
            s *= ( p - std::sqrt(  (vertices[i].getX() - vertices[0].getX())*(vertices[i].getX() - vertices[0].getX()) + (vertices[i].getY() - vertices[0].getY())*(vertices[i].getY() - vertices[0].getY()) ));
        }
        else {
            s *= ( p - std::sqrt(  (vertices[i].getX() - vertices[i+1].getX())*(vertices[i].getX() - vertices[i+1].getX()) + (vertices[i].getY() - vertices[i+1].getY())*(vertices[i].getY() - vertices[i+1].getY()) ));
        }
    }
    return std::sqrt(s);
}


double Ellipse::square() {
    double s{1};
    s *= pi*_a*_b;
    return s;
}
void Ellipse::print() {
    std::cout << _type << ":" << std::endl;
    std::cout << "Цетр:";
    _centre.printPoint();
    std::cout << "Периметр = " << perimeter() << std::endl;
    std::cout << "Площадь = " << square() << std::endl;
}
void Ellipse::setCab(Point centre, double a, double b) {
    _centre = centre;
    _a = a;
    _b = b;
}
double Ellipse::perimeter() {
    return (4 * (pi*_a*_b + (_a - _b)*(_a - _b))/(_a + _b));
}

double Circle::perimeter() {
    return 2*pi*_r;
};
double Circle::square() {
    return pi*_r*_r;
};
void Circle::setCr(Point centre, double r) {
    _centre = centre;
    _r = r;
};
