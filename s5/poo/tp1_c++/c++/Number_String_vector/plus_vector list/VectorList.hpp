#pragma once

#include "String.hpp"

class VectorSt{
   public:
      String *value;
      VectorSt *prev;
      VectorSt *suiv; 
      VectorSt(){
         value = nullptr;
         prev = nullptr;
         suiv = nullptr;
      }
      ~VectorSt (){
         delete value; // you can't use if static
         value = nullptr;
         prev = nullptr;
         suiv = nullptr;
      }
};

class VectorL{
   private:
      VectorSt *vecteur;
      int sizeVectorL;
   public:
  //VectorL() = default;
      VectorL();
      VectorL(int);
      VectorSt *add();
      void add(String);
      void add(int);
      void add(double);
      void add(char);
      void add(VectorL);
      VectorSt *getVect(int);
      String get(int);
      void set(int, String);
      String remove(int);
      int getIndex(String);
      int size();
      void print();
      double* getDoubleVectorL();
      int* getIntVectorL();
};
