#ifndef SHAPE_H
#define SHAPE_H
#include <string>
#include <stdexcept>
#include "p2d.h"

class Shape {
protected:
    std::string color;
public:
    Shape();
    Shape(std::string color);
    virtual ~Shape() {}
    std::string get_color() const;
    void set_color(std::string c);
    virtual double area() = 0;
    virtual double perimeter() = 0;
    virtual void translate(double incX, double incY) = 0;
    virtual void print() = 0;
};
#endif
