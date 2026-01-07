#include "Square.h"
#include <stdexcept>

bool Square::check(Point2D* v) {
    double d01 = Point2D::distance(v[0], v[1]);
    double d12 = Point2D::distance(v[1], v[2]);
    double d23 = Point2D::distance(v[2], v[3]);
    double d30 = Point2D::distance(v[3], v[0]);
    // Un cuadrado tiene todos los lados iguales y las diagonales iguales
    double diag1 = Point2D::distance(v[0], v[2]);
    double diag2 = Point2D::distance(v[1], v[3]);
    return (d01 == d12 && d12 == d23 && d23 == d30 && diag1 == diag2);
}

Square::Square() : Rectangle() {
    Point2D verts[4] = {
        Point2D(1, 1), Point2D(1, -1), Point2D(-1, -1), Point2D(-1, 1)
    };
    set_vertices(verts);
}

Square::Square(std::string color, Point2D* vertices) : Rectangle() {
    this->set_color(color);
    set_vertices(vertices);
}

void Square::set_vertices(Point2D* vertices) {
    if (!check(vertices)) throw std::invalid_argument("No es un cuadrado válido");
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = vertices[i]; // vs es accesible porque es protected en Rectangle
    }
}

void Square::print() { std::cout << *this << std::endl; }

std::ostream& operator<<(std::ostream &out, const Square &square) {
    out << "Square [color: " << square.get_color() << ", vertices: ";
    for (int i = 0; i < 4; i++) out << square.vs[i] << " ";
    out << "]";
    return out;
}
