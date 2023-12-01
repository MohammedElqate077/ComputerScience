#include "Vector.hpp"

#include <iostream>

#include "String.hpp"

Vector::Vector() { // ()default;
  sizeVector = -1;  // = 0;
  // tabString = new String[1];
}

Vector::Vector(int size) { 
   sizeVector = size; 
   //tabString = new String [sizeVector];
   tabString = (String*)malloc(sizeVector*sizeof(String*));
}


void Vector::add(String element) {
  sizeVector++;
  tabString = (String *)realloc(tabString, sizeVector);
  tabString[sizeVector].set(element.get());  // we use t[0];
}

void Vector::add(int element) {
  String *temp = new String(element);
  this->add(*temp);
  delete temp;

  /*sizeVector++;
  tabString = (String*)realloc(tabString, sizeVector);
  tabString[sizeVector - 1].set(element);*/
}
void Vector::add(double element) {
  String *temp = new String(element);
  this->add(*temp);
  delete temp;
}

void Vector::add(char element) {
  String *temp = new String(element);
  this->add(*temp);
  delete temp;
}

void Vector::add(Vector element) {
  for (int i = 0; i <= element.sizeVector; ++i) {
    this->add(element.tabString[i]);
  }
  /*int i = sizeVector +1 ;
  int j = 0;
  sizeVector += element.sizeVector;
  tabString = (String *)realloc(tabString, sizeVector);
  while (i <= sizeVector) {
    tabString[i] = element.tabString[j];
    i++;
    j++;
  }*/
}

String Vector::get(int index) {
  /*String temp(tabString[index].get());
  return temp;*/
  return tabString[index];
}

void Vector::set(int index, String element) {
  tabString[index].set(element.get());  // coder must initial array with 0;
}

String Vector::remove(int index) {
  int i = index;
  String returnString;
  while (i < sizeVector) {
    tabString[i].set(tabString[i + 1].get());
    i++;
  }
  returnString.set(tabString[i].get());
  // delete tabString[i]; //destructor of String not work;
  // cant free memory of last element because not dynamique
  free(tabString[sizeVector].get());
  free(tabString + sizeVector);
  //(tabString + sizeVector) = NULL; //not work;
  sizeVector--;
  tabString = (String *)realloc(tabString, sizeVector);
  return returnString;
}

int Vector::getIndex(String element) {
  int i = 0;
  bool nonExist = true;
  while (i <= sizeVector && nonExist) {
    if (Strcmp(tabString[i], element) == 0) {
      nonExist = false;
    }
    ++i;
  }
  if (nonExist == false)
    return i;
  else
    return -1;
}

int Vector::size() { return sizeVector; }

void Vector::print() {
  if (sizeVector == -1)
     std::cout << "empty vector " << std::endl;
  for (int i = 0; i <= sizeVector; i++) {
    tabString[i].print();
  }
}

int isDoubleInt(char *value) {
  int i = 0;
  int digit = 1;
  int virgule = 0;
  if (value[i] == '-') {
    ++i;
  }
  while (value[i] != '\0') {
    if (value[i] == '.') virgule++;
    if ((virgule == 2) && !isdigit(value[i])) {
      digit = 0;
      break;
    } else
      ++i;
  }
  if (digit && virgule == 1)
    return 1;
  else if (digit)
    return 0;
  else
    return -1;
}

double *Vector::getDoubleVector() {
  double *tabReal = new double[sizeVector];
  int j = 0;
  for (int i = 0; i < sizeVector; i++) {
    if (isDoubleInt(tabString[i].get()) == 1) {
      tabReal[j] = (double)atof(tabString[i].get());
      j++;
    }
  }
  tabReal = (double *)realloc(tabReal, j);
  return tabReal;
}
int *Vector::getIntVector() {
  int *tabInt = new int[sizeVector];
  int j = 0;
  for (int i = 0; i < sizeVector; i++) {
    if (isDoubleInt(tabString[i].get()) == 0) {
      tabInt[j] = (int)atoi(tabString[i].get());
      j++;
    }
  }
  tabInt = (int *)realloc(tabInt, j);
  return tabInt;
}
