#include <iostream>
#include "Shape.h"
#include <ostream>
#include <cmath>
class Rectangle : public Shape {
  private:
    Point2D* vs; 
    static int const N_VERTICES = 4; 


  public:
    //Virtuales heredados
    double area() override {
      double base, altura;
      base = Point2D::distance(vs[0], vs[1]);
      altura = Point2D::distance(vs[1], vs[2]);
      return base*altura;

    }
    double perimeter() override {
      return area()*2;
       
    }
    void translate( double incX, double incY ) override {
    //Movemos los vértices 
     for(int i=0; i < N_VERTICES; i++){
      double newX = vs[i].get_x() + incX;  
      double newY = vs[i].get_y() + incY;
      vs[i] = Point2D(newX, newY);

     } 
    }
    void print() override {
    std::cout << *this;
    }




    Rectangle() : Shape("red") {
      
      vs = new Point2D[N_VERTICES];
      vs[0] = Point2D(-1, 0.5);
      vs[1] = Point2D(1, 0.5);
      vs[2] = Point2D(1, -0.5);
      vs[3] = Point2D(-1,-0.5);

    }
    static bool check(Point2D* vertices){
        return (Point2D::distance(vertices[0],vertices[3]) != Point2D::distance(vertices[1], vertices[2]) &&
            Point2D::distance(vertices[0], vertices[1]) == Point2D::distance(vertices[2], vertices[3]));
    }

    Rectangle(std::string color, Point2D* vertices): Shape(color){
      if (!check(vertices)) {
            throw std::invalid_argument("Vértices no válidos para un rectángulo.");
        }
        vs = new Point2D[N_VERTICES];
        for (int i = 0; i < N_VERTICES; i++) {
            vs[i] = vertices[i];
        }
    }
    Rectangle(const Rectangle &r): Shape(r){
      this->vs = new Point2D[N_VERTICES];
      for (int i = 0; i < N_VERTICES; i++) {
        this->vs[i] = r.vs[i];
    }
    }
    ~Rectangle(){
      delete[] vs;
    }


    
    Point2D get_vertex(int ind)const {
      if(ind < 0 || ind >= N_VERTICES){
        throw std::invalid_argument("Fuera del rango");
      }
      for(int i = 0; i < N_VERTICES; i++){
        if(vs[i] == ind){
          return vs[ind];
        }
      }
    }
    
    Point2D operator[](int ind) const {
      
      if (ind < 0 || ind >= N_VERTICES) {
        throw std::out_of_range("Índice fuera de rango.");
      }
      return vs[ind];
    }

    virtual void set_vertices(Point2D* vertices) {
      if (!check(vertices)) {
        throw std::invalid_argument("Los vértices proporcionados no conforman un rectángulo válido.");
    }

    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = vertices[i];
    }

    
    double cx = (vs[0].get_x() + vs[1].get_x() + vs[2].get_x() + vs[3].get_x()) / 4.0;
    double cy = (vs[0].get_y() + vs[1].get_y() + vs[2].get_y() + vs[3].get_y()) / 4.0;
    vs = new Point2D(cx, cy);
    }

    Rectangle& operator=(const Rectangle &r){
      if (this != &r) {
            Shape::operator=(r);
            delete[] vs;
            vs = new Point2D[N_VERTICES];
            for (int i = 0; i < N_VERTICES; i++) {
                vs[i] = r.vs[i];
            }
        }
        return *this;
    }




    friend std::ostream& operator<<(std::ostream &out, const Rectangle &r) {
     out << "Rectangle [color: " << r.get_color() << ", center: " << r.get_center() << "]\nVertices: ";
      for(int i = 0; i < 4; i++){
        out << "v" << i << r.vs[i] << " ";
      }
     return out;
    }



};
