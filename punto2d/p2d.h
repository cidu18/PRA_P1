#ifndef P2D_H
#define P2D_H
#include <iostream>

class Point2D {
  private: 
     double cordx;
     double cordy;
  public:
    Point2D(double x = 0, double y = 0);
    double get_x() const;
    double get_y() const;
    static double distance(const Point2D &a, const Point2D &b);
    friend bool operator!=(const Point2D &a, const Point2D &b);
    friend bool operator==(const Point2D &a, const Point2D &b);
    friend std::ostream& operator<<(std::ostream &out, const Point2D &p);
};
#endif
