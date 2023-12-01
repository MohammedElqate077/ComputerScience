#include <iostream>
#include "pointCercle.hpp"

using namespace std;

int main(){
   Cercle c1;
   Cercle c2(19,3);
   Cercle c3(19,3,100,100,100);
   Point p1(18,13,13);
   p1.print();
   c1.print();
   c2.print();
   c3.print();

   

   return 0;
}
