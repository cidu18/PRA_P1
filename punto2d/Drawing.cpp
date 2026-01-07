#include "Drawing.h"
#include "../ListLinked.h"
#include "Circle.h"
#include "Square.h"

Drawing::Drawing() { shape = new ListLinked<Shape*>(); }
Drawing::~Drawing() { delete shape; }
void Drawing::add_front(Shape* s) { shape->prepend(s); }
void Drawing::add_back(Shape* s) { shape->append(s); }

void Drawing::print_all() {
    for (int i = 0; i < shape->size(); i++) {
        shape->get(i)->print();
    }
}

double Drawing::get_area_all_circles() {
    double total = 0;
    for (int i = 0; i < shape->size(); i++) {
        Circle* c = dynamic_cast<Circle*>(shape->get(i));
        if (c) total += c->area();
    }
    return total;
}

void Drawing::move_squares(double incX, double incY) {
    for (int i = 0; i < shape->size(); i++) {
        Square* sq = dynamic_cast<Square*>(shape->get(i));
        if (sq) sq->translate(incX, incY);
    }
}
