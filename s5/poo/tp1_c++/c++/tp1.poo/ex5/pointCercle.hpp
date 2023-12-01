#pragma once

class Point {
   private:
      float x,y,z;
   public:
      //Point(float a = 0, float b = 0, float c = 0);
      Point(float a = 0, float b = 0, float c = 0);
      //Point(float, float, float);
      void print();
};

class Cercle : public Point {
   private:
      float centre,rayon;
   public:
      Cercle(float centre = 0, float rayon = 0,float x=0,float y=0, float z=0);
      void print();
};
