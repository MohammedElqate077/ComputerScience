#include "Number.hpp"

#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>

Number::Number(int value) {
  this->value = value;  // (double)intger;
}

Number::Number(double value) { this->value = value; }

long int binaryValue(char *value) {
  int length = (int)strlen(value) - 1;
  int some = 0;
  for (int i = 0; i < length; ++i) some += pow(value[i], length - i);
  return (long int)some;
}

int isBinDoubleInt(char *value) {
  int i = 0;
  int digit = 1;
  int virgule = 0;
  bool isBinary = 1;
  if (value[i] == '-') {
    ++i;
    isBinary = 0;
  }
  while (value[i] != '\0') {
    if (value[i] != '0' || value[i] != '1') isBinary = 0;
    if (value[i] == '.') virgule++;
    if ((virgule == 2) && !isdigit(value[i])) {
      digit = 0;
      break;
    } else
      ++i;
  }
  if (digit && isBinary)
    return 0;
  else if (digit && virgule == 1)
    return 1;
  else if (digit)
    return 2;
  else
    return -1;
}

Number::Number(char *value) {
  if (isBinDoubleInt(value) == 0)
    this->value = binaryValue(value);
  else if (isBinDoubleInt(value) > 0)
    this->value = (double)atof(value);
}

Number::Number(const Number &number) { value = number.value; }

void Number::setValue(int value) {
  this->value = (double)value;  //
}

void Number::setValue(double value) { this->value = value; }

void Number::setValue(char *value) {
  Number *temp = new Number(value);
  this->value = temp->value;
  delete temp;
}

int Number::getIntValue() { return (int)value; }

double Number::getDoubleValue() { return value; }

char *strrevv(char *str) {
  // strrev not work ;
  int i, j;
  char temp;
  for (i = 0, j = (int)strlen(str) - 1; i < j; ++i, --j) {
    temp = str[i];
    str[i] = str[j];
    str[j] = temp;
  }
  return str;
}

char *binaryValue(double tempIntValue) {
  // std::itoa(tempIntValue,temp,2); // not work;
  // this function works for integers values only
  char *temp = new char[2000];
  int i;
  for (i = 0; tempIntValue != 0; ++i) {
    temp[i] = (long long int)tempIntValue % 2 + '0';
    tempIntValue /= 2;
  }
  temp[i + 1] = '\0';
  temp = strrevv(temp);
  for (i = 0; temp[i] != '1'; ++i)
    ;
  char *newTemp = new char[i + 1];
  strcpy(newTemp, temp + i);
  delete[] temp;
  return newTemp;
}

/*//long long int BinaryValue(double value) {
char *BinaryValue(double value) {
  int i = 1;
  value = 149354;
  long long int result = 0;
  while (value != 0) {
    result += ((int)value % 2) * i;
    value /= 2;
    i *= 10;
  }
  std::cout << result << std::endl;
}*/

char *Number::getBinValue() { return binaryValue(value); }

char *Number::getCharValue(int a, int b) {
  char *temp = new char[50];
  char *temp1 = new char[50];
  int i, j, k = 1;
  sprintf(temp, "%lf", value);
  for (j = i = 0; i < a && temp[i] != '.' && temp[i] != '\0'; j++, ++i)
    temp1[j] = temp[i];
  if (b > 0) {
    while (temp[i] != '\0' && temp[i] != '.') i++;
    temp1[j] = '.';
    for (j++, i++; k < b && temp[i] != '\0'; k++, i++, j++) temp1[j] = temp[i];
  }
  temp1[j] = '\0';
  temp1 = (char *)realloc(temp1, (size_t)j * sizeof(char));
  delete temp;
  temp = nullptr;
  return temp1;
}

void Number::genValue() {
  double value = 2;
  const float virgule = 0.108139001;
  srand(time(NULL) * value);
  value = (rand() % 5000000) * pow(-1, rand() % 4);
  value += pow(virgule, rand() % 10);  // or + virgule
}

void Number::operator++() { ++value; }
void Number::operator--() { --value; }
void Number::operator+=(Number &num) { value += num.value; }

void Number::operator-=(Number &num) { value -= num.value; }
