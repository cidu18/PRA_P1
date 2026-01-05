#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include "Shape.h"
#include "Rectangle.h"
#include <ostream>
#include <cmath>
#include <stdexcept>

class Square : public Rectangle {
  private:
    static bool check(Point2D* vertices){
        return (Point2D::distance(vertices[0], vertices[1]) == Point2D::distance(vertices[1], vertices[2]) &&
                Point2D::distance(vertices[2], vertices[3]) == Point2D::distance(vertices[3], vertices[0]) &&
                Point2D::distance(vertices[0], vertices[1]) == Point2D::distance(vertices[3], vertices[0]));
    }

  public:
    Square() : Rectangle() {
        Point2D verts[4] = {
            Point2D(1, 1),
            Point2D(1, -1),
            Point2D(-1, -1),
            Point2D(-1, 1)
        };
        set_vertices(verts);
    }

    Square(std::string color, Point2D* vertices) : Rectangle() {
        this->set_color(color); 
        if (check(vertices)) {
            this->set_vertices(vertices);
        } else {
            throw std::invalid_argument("Los vértices no forman un cuadrado válido");
        }
    }

    void set_vertices(Point2D* vertices) override {
      if (check(vertices)) {
        for (int i = 0; i < this->N_VERTICES; i++) {
            this->vs[i] = vertices[i];
        }
      } else {
        throw std::invalid_argument("Los nuevos vértices no forman un cuadrado válido");
      }
    }

    friend std::ostream& operator<<(std::ostream &out, const Square &square) {
        out << (const Rectangle&)square; 
        return out;
    }
        
    void print() override {
        std::cout << *this << std::endl;
    }
};

#endif
