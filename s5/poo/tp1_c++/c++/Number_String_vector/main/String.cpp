#include "String.hpp"
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>

// using namespace std;

String::String(const char *chaine) {
  this->chaine = new char[strlen(chaine) + 1];
  strcpy(this->chaine, (char *)chaine);
}

String::String(int intger) {
  int nbElement;
  if (intger == 0 || intger == 1)
    nbElement = 1;
  else
    nbElement = ceil(log10(intger)) + 1;
  chaine = new char[nbElement];
  sprintf(chaine, "%d", intger);
  // or use itoa function
}

String::String(double real) {
  int nbElement;
  if (real == 0 || real == 1)
    nbElement = 1;
  else
    nbElement = ceil(log10(real)) + 5 + 1;

  chaine = new char[nbElement];
  snprintf(chaine, nbElement, "%.04lf", real);
  // or use ftoa function
}

String::String(char C) {
  chaine = new char[2];
  *(chaine) = C;
  *(chaine + 1) = '\0';
}

String::String(const String &chaine) {
  this->chaine = new char[strlen(chaine.chaine) + 1];
  strcpy(this->chaine, chaine.chaine);
}

int String::length() { return (int)strlen(chaine); }

// char String::get(int i) { return this->chaine[i]; }
char String::get(int i) { return chaine[i]; }

// char *String::get() { return this->chaine; }
char *String::get() { return chaine; }

void String::set(int i, char c) {
  chaine[i] = c;
}  // tab start from i , user must think from

void String::set(void *ptr) {
  chaine = (char*)ptr; 
}
void String::set(char *chaine) {
  delete[] this->chaine;  // or use realloc function
  this->chaine = new char[strlen(chaine) + 1];
  strncpy(this->chaine, chaine, strlen(chaine));
}

void String::set(int intger) {
  int nbElement;
  if (intger == 0 || intger == 1)
    nbElement = 1;
  else
    nbElement = ceil(log10(intger)) + 1;

  chaine = (char *)realloc(chaine, nbElement * sizeof(char));
  sprintf(chaine, "%d", intger);
  // std::cout << strlen(chaine) << std::endl;
}
void String::set(double real) {
  int nbElement;
  if (real == 0 || real == 1)
    nbElement = 1;
  else
    int nbElement = ceil(log10(real)) + 5 + 1;

  chaine = (char *)realloc(chaine, nbElement * sizeof(char));
  sprintf(chaine, "%.04lf", real);
}

void String::append(char *chaine) {
  int longeur = strlen(this->chaine) + strlen(chaine) + 1;
  this->chaine = (char *)realloc(this->chaine, longeur * sizeof(char));
  // strncat(this->chaine,chaine,strlen(chaine));
  strcat(this->chaine, chaine);
}

void String::append(int intger) {
  String *temp = new String(intger);
  int longeur = strlen(chaine) + strlen(temp->chaine) + 1;
  chaine = (char *)realloc(chaine, longeur * sizeof(char));
  strcat(chaine, temp->chaine);
  delete temp;
}

void String::append(char C) {
  int longeur = strlen(chaine) + 1;
  chaine = (char *)realloc(chaine, longeur * sizeof(char));
  *(chaine + longeur - 1) = C;
  *(chaine + longeur) = '\0';
}

void String::append(float real) {
  String *temp = new String(real);
  int longeur = strlen(chaine) + strlen(temp->chaine) + 1;
  chaine = (char *)realloc(chaine, longeur * sizeof(char));
  strcat(chaine, temp->chaine);
  delete temp;
}

void String::toUpper() {
  char *ptr = chaine;
  while (*ptr != '\0') {
    *ptr = (char)toupper(*ptr);
    ptr++;
  }
}

void String::toLower() {
  char *ptr = chaine;
  while (*ptr != '\0') {
    *ptr = (char)tolower(*ptr);
    ptr++;
  }
}

void String::insert(int i, char *chaine) {
  i -= 1;
  int tempLength = strlen(chaine) + strlen(this->chaine);
  char *temp = new char[tempLength];
  strncpy(temp, this->chaine, i);
  strcat(temp, chaine);
  strcat(temp, this->chaine + i);
  this->chaine = (char *)realloc(this->chaine, tempLength * sizeof(char));
  strcpy(this->chaine, temp);
  delete[] temp;
}

void String::insert(int i, String &chaine) {
  this->insert(i, chaine.chaine);
  // this->insert(i, chaine.get());
  /*i-=1;
  int tempLength = strlen(chaine.chaine) + strlen(this->chaine) +1;
  char *temp = new char [tempLength];
  strncpy(temp,this->chaine,i);
  strcat(temp,chaine.chaine);
  strcat(temp,this->chaine+i);
  this->chaine = (char*)realloc(this->chaine,tempLength * sizeof(char));
  strcpy(this->chaine,temp);
  delete [] temp;
  */
}

void String::insert(int i, int intger) {
  String *temp = new String(intger);
  this->insert(i, temp->chaine);
}

void String::insert(int i, double real) {
  String *temp = new String(real);
  this->insert(i, temp->chaine);
}

void String::insert(int i, char C) {
  String *temp = new String(C);
  this->insert(i, temp->chaine);
}

String String::substring(int i, int j) {
  char *temp = new char[j - i + 2];  // what about NULL caractere so +2=1+1;
  int k;
  i--;
  j--;
  for (k = 0; i <= j; ++k, ++i) temp[k] = chaine[i];
  temp[k] = '\0';
  String subchaine(temp);
  delete temp;
  return subchaine;
}

int String::pos(const char *chaine) {
  /*char *ptr = strstr(this->chaine, chaine);
  if (ptr) return ptr - this->chaine;  // +1;
  return -1;
  */
  int i, j, k;
  i = j = k = 0;
  if (this->length() >= (int)strlen(chaine)) {
    while ((i < (int)strlen(chaine)) && (j < this->length())) {
      if (chaine[i] == this->chaine[j]) {
        ++i;
        ++j;
      } else {
        i = 0;
        // if j the first occurrence should not increment j
        if (chaine[0] != this->chaine[j]) j++;
        k = j;
      }
    }
  } else
    return -1;
  if (i == (int)strlen(chaine))
    return k;
  else
    return -1;
  //*/
}

int String::pos(String &chaine) { return this->pos(chaine.chaine); }

void String::print() { std::cout << chaine << std::endl; }

int String::intValue() {
  int i = 0;
  int digit = 1;
  if (chaine[i] == '-') ++i;
  while (chaine[i] != '\0') {
    if (!isdigit(chaine[i])) {
      digit = 0;
      break;
    } else
      ++i;
  }
  if (digit) return atoi(chaine);
  // or create and return pointer of int for return value or NULL if is not a
  // int value to avoid warning and confuse;
}

double String::doubleValue() {
  int i = 0;
  int digit = 1;
  int virgule = 0;
  if (chaine[i] == '-') ++i;
  while (chaine[i] != '\0') {
    if (chaine[i] == '.') virgule++;
    if ((virgule == 2) && !isdigit(chaine[i])) {
      digit = 0;
      break;
    } else
      ++i;
  }
  if (digit) return atof(chaine);
  // or create and return pointer of double for return value or NULL if is not a
  // double value to avoid warning and confuse;
}

String String::operator+(const String &chaine) {
  String temp(this->chaine);
  temp.append(chaine.chaine);
  return temp;
}

String &String::operator=(const String &chaine) {
  if (this->chaine != NULL) {
    delete this->chaine;
    this->chaine = nullptr;
  }
  this->chaine = new char[strlen(chaine.chaine) + 1];
  strcpy(this->chaine, chaine.chaine);
  return *this;  // or use copy constructor
}

/*

String String::operator+(String &chaine) {
  String temp(this->chaine);
  temp.append(chaine.chaine);
  return temp;
}

String String::operator=(String &chaine) {
  this->chaine = new char[strlen(chaine.chaine) + 1];
  strcpy(this->chaine, chaine.chaine);
  return *this;  // or use copy constructor
}*/

/*bool String::Strcmp(String &chaine) { member of class String
bool String::Strcmp(String &chaine) {
  if (strcmp(this->chaine, chaine.chaine) == 0) return 1;
  return 0;
}*/

bool Strcmp(String &chaine1, String &chaine2) {  // friend function;
  // if(chaine1.pos(chaine2.chaine) >= 0 && chaine1.length() ==
  // chaine2.length())
  if (chaine1.pos(chaine2) >= 0 && chaine1.length() == chaine2.length())
    return 0;
  else
    return -1;
}
