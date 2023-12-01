#pragma once

#include "String.hpp" 

class Person {
   protected:
      String *nom;
      String *prenom;
      String *dateNaissance;
   public:
      Person(const char *a=" ", const char *b=" ", const char *c=" ");
      ~Person();
      virtual void print();
};

class Employe:public Person {
   protected:
      float salaire;
   public:
      //Employe(bool a = 0, float salaire = 0);
      Employe(bool a = 0, float salaire = 0,const char *aa=" ", const char *bb=" ", const char *cc=" ");
       virtual void print();
};

class Chef:public Employe {
   private:
      String *service;
   public:
      //Chef(bool a = 0, const char *service = " ");
      Chef(bool a = 0, const char *service = " ",bool a_ = 0, float salaire = 0,const char *aa_=" ", const char *bb_=" ", const char *cc_=" ");
      void print();
};
