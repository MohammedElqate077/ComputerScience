#pragma once

class Number {
 private:
  double value;

 public:
  Number(){};
  Number(int);
  Number(double);
  Number(char *);
  Number(const Number &);
  void setValue(int);
  void setValue(double);
  void setValue(char *);
  int getIntValue();
  double getDoubleValue();
  char *getBinValue();
  char *getCharValue(int, int);
  void genValue();  // random generate value;
  void operator++();
  void operator--();
  void operator+=(Number &);
  void operator-=(Number &);
};
