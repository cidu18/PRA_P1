#include "Rectangle.h"
#include <stdexcept>

Rectangle::Rectangle() : Shape("red") {
    vs = new Point2D[N_VERTICES];
    vs[0] = Point2D(-1, 0.5); vs[1] = Point2D(1, 0.5);
    vs[2] = Point2D(1, -0.5); vs[3] = Point2D(-1, -0.5);
}

Rectangle::Rectangle(std::string color, Point2D* vertices) : Shape(color) {
    if (!check(vertices)) throw std::invalid_argument("Vértices no válidos");
    vs = new Point2D[N_VERTICES];
    for (int i = 0; i < N_VERTICES; i++) vs[i] = vertices[i];
}

Rectangle::Rectangle(const Rectangle &r) : Shape(r) {
    vs = new Point2D[N_VERTICES];
    for (int i = 0; i < N_VERTICES; i++) vs[i] = r.vs[i];
}

Rectangle::~Rectangle() { delete[] vs; }

bool Rectangle::check(Point2D* v) {
    double d01 = Point2D::distance(v[0], v[1]);
    double d23 = Point2D::distance(v[2], v[3]);
    double d12 = Point2D::distance(v[1], v[2]);
    double d03 = Point2D::distance(v[0], v[3]);
    return (d01 == d23 && d12 == d03);
}

double Rectangle::area() {
    return Point2D::distance(vs[0], vs[1]) * Point2D::distance(vs[1], vs[2]);
}

double Rectangle::perimeter() {
    return (Point2D::distance(vs[0], vs[1]) + Point2D::distance(vs[1], vs[2])) * 2;
}

void Rectangle::translate(double incX, double incY) {
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = Point2D(vs[i].get_x() + incX, vs[i].get_y() + incY);
    }
}

void Rectangle::print() { std::cout << *this << std::endl; }

void Rectangle::set_vertices(Point2D* vertices) {
    if (!check(vertices)) throw std::invalid_argument("Vértices no válidos");
    for (int i = 0; i < N_VERTICES; i++) vs[i] = vertices[i];
}

Rectangle& Rectangle::operator=(const Rectangle &r) {
    if (this != &r) {
        Shape::operator=(r);
        delete[] vs;
        vs = new Point2D[N_VERTICES];
        for (int i = 0; i < N_VERTICES; i++) vs[i] = r.vs[i];
    }
    return *this;
}

std::ostream& operator<<(std::ostream &out, const Rectangle &r) {
    out << "Rectangle [color: " << r.get_color() << ", vertices: ";
    for (int i = 0; i < 4; i++) out << r.vs[i] << " ";
    out << "]";
    return out;
}


Point2D Rectangle::get_vertex(int ind) const {
    if (ind < 0 || ind >= N_VERTICES) {
        throw std::out_of_range("Índice de vértice fuera de rango");
    }
    return vs[ind];
}

Point2D Rectangle::operator[](int ind) const {
    return get_vertex(ind);
}


