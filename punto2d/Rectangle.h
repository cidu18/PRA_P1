#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include "Shape.h"
#include "p2d.h"

class Rectangle : public Shape {
    protected:
        Point2D* vs; // Atributo protegido para que Square lo herede
        static const int N_VERTICES = 4; // Constante compartida

    public:
        Rectangle();
        Rectangle(std::string color, Point2D* vertices);
        Rectangle(const Rectangle &r);
        virtual ~Rectangle();

        static bool check(Point2D* vertices);
        
        double area() override;
        double perimeter() override;
        void translate(double incX, double incY) override;
        virtual void print() override;

        Point2D get_vertex(int ind) const;
        Point2D operator[](int ind) const;
        virtual void set_vertices(Point2D* vertices);
        Rectangle& operator=(const Rectangle &r);

        friend std::ostream& operator<<(std::ostream &out, const Rectangle &r);
};

#endif
