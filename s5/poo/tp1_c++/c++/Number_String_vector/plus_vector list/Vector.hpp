#pragma once

#include "String.hpp"

class Vector {
 private:
  String *tabString;
  int sizeVector ;
 public:
  //Vector() = default;
  Vector();
  Vector(int);
  void add(String);
  void add(int);
  void add(double);
  void add(char);
  void add(Vector);
  String get(int);
  void set(int, String);
  String remove(int);
  int getIndex(String);
  int size();
  void print();
  double* getDoubleVector();
  int* getIntVector();
};
