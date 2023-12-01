#include <iostream>
#include "pointCercle.hpp"

//Point::Point(float a = 0,float b = 0, float c = 0){
Point::Point(float a,float b, float c){
  x = a; 
  y = b;
  z = c;
}

void Point::print(){
   std::cout << "x = " << x  << " |y = " << y  << " |z = " << z <<  std::endl;
}

Cercle::Cercle(float centre, float rayon,float x,float y ,float z):Point(x,y,z){
   this->centre = centre;
   this->rayon = rayon;
}

void Cercle::print(){
   std::cout << "centre = " << centre << "|rayon = " << rayon << " |";
   Point::print(); 
}
