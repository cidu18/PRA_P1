#include "p2d.h"
#include <cmath>

Point2D::Point2D(double x, double y) : cordx(x), cordy(y) {}

double Point2D::get_x() const { return cordx; }

double Point2D::get_y() const { return cordy; }

double Point2D::distance(const Point2D &a, const Point2D &b) {
    return std::sqrt(std::pow(a.cordx - b.cordx, 2) + std::pow(a.cordy - b.cordy, 2));
}

bool operator!=(const Point2D &a, const Point2D &b) {
    return (a.cordx != b.cordx || a.cordy != b.cordy);
}

bool operator==(const Point2D &a, const Point2D &b) {
    return (a.cordx == b.cordx && a.cordy == b.cordy);
}

std::ostream& operator<<(std::ostream &out, const Point2D &p) {
    out << "(" << p.cordx << "," << p.cordy << ")";
    return out; 
}
