#pragma once

class String {
 private:
  char *chaine;

 public:
  String() = default;  // {chaine = new char [sizeof(char)];};
  String(const char *);
  String(int);
  String(double);
  String(char);
  String(const String &) ;
  //~String() { delete chaine; };
  ~String() = default;
  int length();
  char get(int i);
  char *get();
  void set(int i, char c);
  void set(char *);
  void set(int);
  void set(double);
  void append(char *);
  void append(int);
  void append(float);
  void append(char);
  void insert(int, int);
  void insert(int, double);
  void insert(int, char);
  void toUpper();
  void toLower();
  void insert(int, char *);
  void insert(int, String &);
  String substring(int, int);
  int pos(const char *);
  int pos(String &);
  void print();
  int intValue();
  double doubleValue();
  //String operator+(String &);
  // String operator=(String &);
  String operator+(const String &);
  String &operator=(const String &);
  //bool Strcmp(String &chaine); 
  friend bool Strcmp(String &chaine1,String &chaine2);//friend function;
};