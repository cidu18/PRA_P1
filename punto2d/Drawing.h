#ifndef DRAWING_H
#define DRAWING_H
#include "../list.h"
#include "Shape.h"

class Drawing {
  private:
    list<Shape*>* shape;
  public:
    Drawing();
    ~Drawing();
    void add_front(Shape* s);
    void add_back(Shape* s);
    void print_all();
    double get_area_all_circles();
    void move_squares(double incX, double incY);
};
#endif
