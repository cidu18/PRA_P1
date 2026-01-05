#ifndef DRAWING_H
#define DRAWING_H

#include <iostream>
#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Square.h"
#include "../List.h"
#include "../ListLinked.h"

class Drawing {
  private:
    list<Shape*>* shape;

  public:
    Drawing() {
      shape = new ListLinked<Shape*>();
    }
    
    ~Drawing() {
      delete shape;
    }

    void add_front(Shape* s) {
      shape->prepend(s);
    }

    void add_back(Shape* s) {
      shape->append(s);
    }

    void print_all() {
      for (int i = 0; i < shape->size(); i++) {
        Shape* s = shape->get(i);
        s->print(); 
      }
    }

    double get_area_all_circles() {
      double total = 0;
      for (int i = 0; i < shape->size(); i++) {
        Shape* s = shape->get(i);
        Circle* c = dynamic_cast<Circle*>(s);
        if (c != nullptr) {
          total += c->area();
        }
      }
      return total;
    }

    void move_squares(double incX, double incY) {
      for (int i = 0; i < shape->size(); i++) {
        Shape* s = shape->get(i);
        Square* sq = dynamic_cast<Square*>(s);
        if (sq != nullptr) {
          sq->translate(incX, incY);
        }
      }
    }
};
#endif
