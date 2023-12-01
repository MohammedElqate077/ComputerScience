#include <iostream>

#include "Vector.hpp"
#include "String.hpp"

Vector::Vector() {  // ()default;
  sizeVector = 0;   // = 0;
  // tabString = new String[1];
}

Vector::Vector(int size) {
  sizeVector = size;
  tabString = new String[sizeVector];
  // tabString = (String *)malloc(sizeVector * sizeof(String));
}

// void *newRealloc(void *element1, size_t size) { void *tmp = malloc(size); }

void Vector::add(String element) {
  sizeVector++;
  if (sizeVector > 1) {  // for reallocation of tabString;
    String *tempString = new String[sizeVector];
    for (int i = 0; i < sizeVector - 1; i++) {
      tempString[i] = tabString[i];
      /*
      char *ptr = NULL; // or befor for loop;
      ptr = tabString[i].get();
      free(ptr);
      ptr = NULL;
      tabString[i].set((void*)ptr);
      */
    }

    delete[] tabString;
    tabString = nullptr;

    tempString[sizeVector-1] = element;
    tabString = new String[sizeVector];
    //tabString = tempString; // copy of pointer , tempString exist all time
    for (int i = 0; i < sizeVector; i++) {
      tabString[i] = tempString[i];
   // we can use the same at above;
    }
    delete[] tempString;
    tempString = nullptr;
  } else {
    tabString = new String[1];
    tabString[0] = element;
  }
  // tempString[sizeVector].set(element.get());  // we use t[0];
}

void Vector::add(int element) {
  String *temp = new String(element);
  this->add(*temp);
  delete temp;

  /*sizeVector++;
  tabString = (String *)realloc(tabString, sizeVector * sizeof(String ));
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
   String emptyString("");
  for (int i = 0; i < element.sizeVector; ++i) {
     if(element.tabString[i].get() != NULL)
        this->add(element.tabString[i]);
     //else this->add(emptyString);
  }
  /*int i = sizeVector +1 ;
  int j = 0;
  sizeVector += element.sizeVector;
  tabString = (String *)realloc(tabString, sizeVector * sizeof(String ));
  while (i < sizeVector) {
    tabString[i] = element.tabString[j];
    i++;
    j++;
  }*/
}

String Vector::get(int index) {
  /*String temp(tabString[index].get());
  return temp;*/
   if(index < sizeVector)
      return tabString[index];
   //else std::cout << "this index must be  under size of vector" << std::endl;
}

void Vector::set(int index, String element) {
   if(index >= sizeVector)
      ;//std::cout << "this index must be under size of vector" << std::endl;
   else
      tabString[index].set(element.get());  // coder must initial array with 0;
}

/*String Vector::remove(int index) {
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
 //tabString = (String *)realloc(tabString, sizeVector * sizeof(String)); // this not work remember
 tabString = (String *)realloc(tabString, sizeVector * sizeof(String)); // this not work remember
  return returnString;
}*/

String Vector::remove(int index) {
  int i = 0;
  char *ptr;
  String returnString;
  String *tempTabString = new String [sizeVector - 1];
  while (i < sizeVector) {// sizeVector -1 for i+1 segmentation false; line 136
     if(i < index ){
        tempTabString[i].set(tabString[i].get());// we can use assigment operator (=);
     }
     else {
        if (i == index)
           returnString.set(tabString[i].get());
        if(i < sizeVector - 1)
           tempTabString[i].set(tabString[i + 1].get());
      }
     i++;
  }
  delete []tabString;
  sizeVector--;
  tabString = new String [sizeVector];
  for (int i = 0; i< sizeVector; ++i){
     tabString[i] = tempTabString[i];
  }
  delete [] tempTabString;
  return returnString;
}

int Vector::getIndex(String element) {
  int i = 0;
  bool nonExist = true;
  while (i < sizeVector && nonExist) {
    if (Strcmp(tabString[i], element) == 0) {
      nonExist = false;
    }
    ++i;
  }
  if (nonExist == false)
    return i - 1;
  else
    return -1;
}

int Vector::size() { return sizeVector; }

void Vector::print() {
  //if (sizeVector == 0) ;//std::cout << "empty vector " << std::endl;
  for (int i = 0; i < sizeVector; i++) {
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
  tabReal = (double *)realloc(tabReal, j * sizeof(double));
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
  tabInt = (int *)realloc(tabInt, j * sizeof(int));
  return tabInt;
}
