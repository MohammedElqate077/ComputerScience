#include <iostream>
//#include "String.hpp" 
#include "fullObject.hpp"

Person::Person(const char *a, const char *b, const char *c){
   nom = new String(a);
   prenom = new String(b);
   dateNaissance = new String(c);
}

Person::~Person(){
   delete nom;
   delete prenom;
   delete dateNaissance;
}

void Person::print(){
   std::cout << "nom :";nom->print();
   std::cout << "prenom :";prenom->print();
   std::cout << "dateNaissance :";dateNaissance->print();
}

//Employe://:Employe(bool a, float salaire){
Employe::Employe(bool a, float salaire,const char *aa, const char *bb, const char *cc):Person(aa,bb,cc){
   if(a){
      std::cout << "salire of employe:" << std::endl;
      std::cin >> this->salaire;
   }
   else this->salaire = salaire;
}

void Employe::print(){
   std::cout << "salaire :" << salaire << std::endl;
   Person::print();
}

//Chef::Chef(bool a, const char *service){
Chef::Chef(bool a, const char *service,bool a_, float salaire_,const char *aa_, const char *bb_, const char *cc_ ):Employe(a_,salaire_,aa_,bb_,cc_){
   if(a){
      char temp[100];
      std::cout << "service:" << std::endl;
      std::cin >> temp;
      this->service->set(temp);
   }
  // else this->service->set((char*)service); this is fault no alocation for service;
  this->service = new String((char*)service);
}


void Chef::print(){
   std::cout << "service :" << service->get() <<  std::endl;
   Employe::print();
}
