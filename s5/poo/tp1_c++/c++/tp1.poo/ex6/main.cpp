#include <iostream>
#include "fullObject.hpp"

using namespace std;
int main(){
   Person person0;
   Person person1("mohmmed", "fsdm", "1/1/2021");
   Employe empl0;
   Employe empl1(0,10000);
   Employe empl3(0,300000,"ousama","efsdm","23/23/1324");
   Chef chef0;
   Chef chef1(0,"chef departement");
   Chef chef3(0,"police",0,18000,"meryem","fihria","23/23/1000");
   Chef chef4(0,"police",1,18000,"meryem","fihria","23/23/1000");
   person0.print();
   cout << "\n------------------------------------------------\n" << endl;
   person1.print();
   cout << "\n------------------------------------------------\n" << endl;
   empl0.print();
   cout << "\n------------------------------------------------\n" << endl;
   empl1.print();
   cout << "\n------------------------------------------------\n" << endl;
   empl3.print();
   cout << "\n------------------------------------------------\n" << endl;
   chef0.print();
   cout << "\n------------------------------------------------\n" << endl;
   chef1.print();
   cout << "\n------------------------------------------------\n" << endl;
   chef3.print();
   cout << "\n------------------------------------------------\n" << endl;
   chef4.print();
}
