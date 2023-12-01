#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>

#include "automatepredictive.hpp"

using namespace std;
// void testFunction();

int main() {
  int choi = 0;
  AutomatePredictive *aut = new AutomatePredictive();

  cout << "       NOTE !!" << endl;
  cout << "1 - les caractere majuscule nom terminale" << endl;
  cout << "2 - les caractere minuscule terminale" << endl;
  cout << "3 - $ pour marquer EOF input stream " << endl;
  cout << "4 - # pour marquer epsilone" << endl;
  cout << "5 - should be LL(1) and use | operator to Vn have multiple production" << endl;
  cout << "\nentrer votre choix !!! exemple cour pour le test(0) || construire grammaire(1) __(0 ou 1): ";

  cin >> ws;// pour cleaner the buffer;
  cin >> choi;

  if (choi)
    aut->construireGrammaire();  // should use this;
  else
    aut->construireGrammaireAll();  // just for test exercice cour here;

  cout << "\n\n calcul de first" << endl;
  for (int k = 0; k < strlen(aut->Vn); k++) {
    aut->tampon = aut->first(aut->Vn[k]);
    cout << aut->Vn[k] << ": ";
    aut->print(aut->tampon);
  }

  cout << "\n calcul de follow" << endl;
  for (int k = 0; k < strlen(aut->Vn); k++) {
    aut->Ftampon = aut->follow(aut->Vn[k]);
    cout << aut->Vn[k] << ": ";
    aut->print(aut->Ftampon);
  }

  delete aut;
}