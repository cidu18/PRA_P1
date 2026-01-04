#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include "p2d.h"

class Shape {
  protected:
    std::string color;  

  public:
    Shape(): color("red"){}

    Shape(std::string color){
       if(color == "red" || color == "green" || color == "blue"){
        this-> color = color;
      } else {throw std::invalid_argument("Color seleccionado no válido");}
   }

    std::string get_color() const {
      return color;

    }

    void set_color(std::string c){
       if(c == "red" || c == "green" || c == "blue"){
        this-> color = c;
      } else {throw std::invalid_argument("Color seleccionado no válido");}
      

    }

    virtual double area() = 0;
    virtual double perimeter() = 0;
    virtual void translate(double incX, double incY) = 0; 
    virtual void print() = 0; 











};

#endif
