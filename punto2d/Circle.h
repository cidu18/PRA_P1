#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include "Shape.h"
#include <ostream>
#include <cmath>
class Circle : public Shape {
  private:
    Point2D center; 
    double radius; 


  public:
    //Virtuales heredados
    double area() override {
      double area;
      area = M_PI*pow(radius, radius);
      return area;
    }
    double perimeter() override {
      double perimeter; 
      perimeter = 2*M_PI*radius; 
      return perimeter; 
    }
    void translate( double incX, double incY ) override {
      double nuevoX = center.get_x() + incX;
      double nuevoY = center.get_y() + incY;
      center = Point2D(nuevoX, nuevoY);
    }

    void print() override {
      std::cout << *this;
    }






    Circle(): Shape("red"), center(0,0), radius(1){}
    Circle(std::string color, Point2D center, double radius): Shape(color), center(center), radius(radius){}
    Point2D get_center()const {
      return center;
    }
    void set_center(Point2D p){
      center = p; 
    } 
    double get_radius()const {
      return radius; 
    }
    void set_radius(double r){
      radius = r; 
    }

    friend std::ostream& operator<<(std::ostream &out, const Circle &c) {
    out << "Circle [color: " << c.color 
        << ", center: " << c.center  
        << ", radius: " << c.radius << "]";
    return out;
}



};
#endif
