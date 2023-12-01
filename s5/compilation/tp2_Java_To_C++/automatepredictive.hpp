#pragma once
#include <cstring>
#include <iostream>
#include <string>

class AutomatePredictive {
 public:
  int partieDroiteSize;
  char *Vt;
  char *Vn;
  char *tampon;
  char *Ftampon;
  char *partieGauche;
  std::string *partieDroite;
  std::string *stringTest;
  AutomatePredictive();
  ~AutomatePredictive() {
    delete[] Vt;
    delete[] Vn;
    delete[] tampon;
    delete[] Ftampon;
    delete[] partieGauche;
    delete[] partieDroite;
    delete[] stringTest;
    Vt = Vn = tampon = Ftampon = partieGauche = nullptr;
    partieDroite = stringTest = nullptr;
  }

  void print(char *table);
  void construireGrammaire();     // pour que l'utilisateur definie un grammaire
  void construireGrammaireAll();  // exemple de test de cour
  void remplirNonTerminal();      // evidant;
  void remplirTerminal();
  bool isEpsilon(const std::string &droite);//si est un epsilon(#)
  char *add(char *table, char symbol, bool check = 1);  // ajouter symbol dans char arry
  std::string *add(std::string *table, const std::string &symbol, const int &size, bool check = 1);//de meme ,check pour verfier si deja dans le tableau (0 ne check pas)
  char *first(char symbol);    // clacule des premier
  char *follow(char symbol);   // calcule des suivant;
  bool axiome(char symbol);  // si symbol axiaome (start production)
  bool isTerminal(char symbol);    // si sybole est terminale;
  bool alphaX(const std::string &str, char X); //si un non termianle a la fin
  bool alpha(const std::string &str) ;//si 1 char of str is terminal

  void testFunction() {  // fonction pour construire le test par default
    char temp[] = {'E', 'B', 'T', 'C', 'F', '\0'};
    char temp0[] = {'+', '-', '*', '(', ')', '/', 'n', '\0'};
    stringTest =
        new std::string[5]{"TB", "+TB|-TB|#", "FC", "*FC|/FC|#", "(E)|n"};
        //exemple de cour;
    Vn = new char[strlen(temp) + 1];
    Vt = new char[strlen(temp0) + 1];
    strcpy(Vn, temp);
    strcpy(Vt, temp0);
  }
};