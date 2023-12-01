#include <iostream>
#include <cstdlib>
//#include <cmath>
#include "String.hpp"
#include "Vector.hpp"

using namespace std;

int main() {
 Vector Vect1,Vect2(7);

 String str1("mohammed"), str2(23.453);
 String str4("OUSSAMA");
 String str5('3');

 char tempChaine[5];
 String tempString("SMI1");

 Vect2.set(1,str1);
 Vect1.add(str1);
 Vect1.add(2021);
 Vect1.add(19.99);
 Vect1.add('A');
 Vect1.set(4,str4); // index must be < sizeVector ; like strlen();
 Vect1.print();

  Vect1.add(Vect2);

  cout << Vect1.get(3).get(); 
  cout << Vect1.get(9).get(); 
   
  cout << str1.get() << endl;
  cout << str4.get() << endl;
  // cout << *(int *)str5.get() << endl;

  for(int i=5; i <=10; i++){
     sprintf(tempChaine,"SMI%d",i);
     tempString.set(tempChaine);
  }

  Vect1.print();
  cout << Vect1.remove(5).get() << endl;
  cout << Vect1.getIndex(str4) << endl;
  cout << Vect1.getIndex(str2) << endl;
  Vect1.print();
  cout << Vect1.size() << endl;
  // char bbb[] = "1234567890";
 String bbb("-11-2.34.6");
  cout << "test value " << bbb.doubleValue() << endl;
  str4.append('X');
  // cout << strlen(bbb) << endl;

  // char bb1 [6] ; strcpy(bb1,bbb+3);
  str1.toUpper();
  str4.toLower();
  str4.insert(5, 'W');
  cout << str1.get() << endl;
  cout << str4.get() << endl;
  //String str6.set(str4.substring(2,8));
 String str6 = str4.substring(3, 7);
  cout << str6.get() << endl;
  // cout << str4.pos(str6.get()) + 1 << endl;
 String str7("Use braibrain your brain and heart");
  cout << "position " << str7.pos("brain") << endl;
  cout << "position " << str4.pos(str6) << endl;
  cout << "\t\t\n" << endl;
  str1 = str2 + str4;
  str1.print();
 String str8 = str1;
  str8.print();

  return 0;
}
