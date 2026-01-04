#ifndef P2D_H
#define P2D_H

#include <iostream>
#include <cmath>

class Point2D{
  private: 
    
     double cordx;
     double cordy;

  public:
    Point2D(double x = 0, double y = 0) : cordx(x), cordy(y){}
    double get_x() const { return cordx; }
    double get_y() const { return cordy; }
    static double distance(const Point2D &a, const Point2D &b){
      
      double dx = a.cordx - b.cordx;
      double dy = a.cordy - b.cordy;


      double dist = sqrt((std::pow(dx, 2))+(std::pow(dy, 2)));

      return dist; 
      
    }
      bool friend operator!=(const Point2D &a, const Point2D &b){
      
      return (a.cordx != b.cordy);



    } 
    bool friend operator==(const Point2D &a, const Point2D &b){
      
      return (a.cordx == b.cordy);



    }
    friend std::ostream& operator<<(std::ostream &out, const Point2D &p){
       
        out << p.cordx << "," << p.cordy << std::endl;
        return out; 



    }





};

#endif
