#include "automatepredictive.hpp"
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>

AutomatePredictive::AutomatePredictive() {
   partieDroiteSize = 0;
   Vt = new char[20];
   Vn = new char[20];
   tampon = new char[0];
   Ftampon = new char[0];
   partieGauche = new char[0];
   std::string *partieDroite = new std::string[0];
}

void AutomatePredictive::print(char *table) {
   std::cout << "{";
   for (int i = 0; i < strlen(table); i++) {
      if (i == 0) {
         std::cout << table[i];
      } else {
         std::cout << ", " << table[i];
      }
   }
   std::cout << "}" << std::endl;
}

void AutomatePredictive::remplirNonTerminal() {
   char aff;
   int i = 0;
   do {
      std::cout << "Saisir un non terminal: ";
      std::cin >> aff;
      if (aff != '$') {
         Vn = add(Vn, aff);
         i++;
      }
   } while (aff != '$');
}

void AutomatePredictive::remplirTerminal() {
   char aff;
   int i = 0;
   do {
      std::cout << "Saisir un terminal: ";
      std::cin >> aff;
      if (aff != '$') {
         Vt = add(Vt, aff);
      }
      i++;
   } while (aff != '$');
}

void AutomatePredictive::construireGrammaire() {
   std::string str;
   remplirNonTerminal();
   remplirTerminal();
   int i = 0;
   while (Vn[i] != '\0') {
      std::cout << Vn[i] << " --> ";
      std::cin >> std::ws;  // or use cin.ignore() function; to clear the buffer;
      std::getline(std::cin, str);
      if (str.find('|') != std::string::npos) {  // pour diviser si |
         std::stringstream partieStr(str);
         while (std::getline(partieStr, str, '|')) {
            partieGauche = add(partieGauche, Vn[i], 0);
            partieDroite = add(partieDroite, str, partieDroiteSize, 0);
            partieDroiteSize++;
         }
      } else {
         partieGauche = add(partieGauche, Vn[i], 0);
         partieDroite = add(partieDroite, (const std::string)str, partieDroiteSize, 0);
         partieDroiteSize++;
      }
      i++;
   }
}

void AutomatePredictive::construireGrammaireAll() {
   int i = 0;
   std::string str;
   testFunction();  // this for just test;
   std::cout << "the grammer with the production is :" << std::endl;
   while (Vn[i] != '\0') {
      std::cout << Vn[i] << " --> " << stringTest[i] << std::endl;
      i++;
   }
   i = 0;
   while (i < 5) {
      str = stringTest[i];
      if (str.find('|') != std::string::npos) {  // pour diviser si |
         std::stringstream partieStr(str);
         while (std::getline(partieStr, str, '|')) {
            partieGauche = add(partieGauche, Vn[i], 0);
            partieDroite = add(partieDroite, str, partieDroiteSize, 0);
            partieDroiteSize++;
         }
      } else {
         partieGauche = add(partieGauche, Vn[i], 0);
         partieDroite = add(partieDroite, (const std::string)str, partieDroiteSize, 0);
         partieDroiteSize++;
      }
      i++;
   }
}

char *AutomatePredictive::add(char *table, char symbol, bool check) {
   if (table == nullptr || (int)strlen(table) == 0) {
      table = new char[2];
      table[0] = symbol;
      table[1] = '\0';
      return table;
   }
   if (check) {
      for (int i = 0; i < strlen(table); i++) {
         if (table[i] == symbol) {
            return table;
         }
      }
   }
   char *newTable = new char[strlen(table) + 2];
   strcpy(newTable, table);
   newTable[strlen(table)] = symbol;
   newTable[strlen(newTable)] = '\0';
   return newTable;
}
std::string *AutomatePredictive::add(std::string *table, const std::string &symbol, const int &size, bool check) {
   std::string *newTable = new std::string[size + 1];
   for (int i = 0; i < size; i++) {
      if (check && table[i] == symbol)
         return table;
      else
         newTable[i] = table[i];
   }
   newTable[size] = symbol;
   delete[] table;
   table = nullptr;
   return newTable;
}

bool AutomatePredictive::isEpsilon(const std::string &droite) {
   if (droite.length() == 1) {
      return droite[0] == '#';
   }
   return false;
}

bool AutomatePredictive::axiome(char symbol) {
   return partieGauche[0] == symbol;
}

bool AutomatePredictive::isTerminal(char symbol) {
   for (int i = 0; i < strlen(Vt); i++)
      if (symbol == Vt[i]) return true;
   return false;
}

bool AutomatePredictive::alpha(const std::string &droite) {
   return isTerminal(droite[0]);
}

bool AutomatePredictive::alphaX(const std::string &str, char X) {
   return str[str.length() - 1] == X;
}

char *AutomatePredictive::first(char symbol) {
   char *EnFirst = nullptr;
   EnFirst = new char[0]; EnFirst[0] = '\0';

   int theRightsSize = 0;
   std::string *theRights = new std::string[theRightsSize];
   for (int i = 0; i < strlen(partieGauche); i++) {
      if (partieGauche[i] == symbol) {
         theRights = add(theRights, partieDroite[i], theRightsSize);
         theRightsSize++;
      }
   }
   for (int j = 0; j < theRightsSize; j++) {
      if (isEpsilon(theRights[j]))
         EnFirst = add(EnFirst, '#');
      else if (alpha(theRights[j]))
         EnFirst = add(EnFirst, theRights[j][0]);
      else {
         bool foundEpsilon = true;
         for (int k = 0; k < theRights[j].length() && foundEpsilon; k++) {
            foundEpsilon = false;
            // tampon = first(theRights[k].at(k));
            tampon = first(theRights[k][k]);
            for (int h = 0; h < strlen(tampon); h++) {
               if (tampon[h] != '#') {
                  EnFirst = add(EnFirst, tampon[h]);
               } else {
                  foundEpsilon = true;
               }
            }
         }
         if (foundEpsilon) {
            EnFirst = add(EnFirst, '#');
         }
      }
   }
   return EnFirst;
}

char *AutomatePredictive::follow(char symbol) {
   char *EnFollow = new char[0];
   EnFollow[0] = '\0';
   if (axiome(symbol)) {
      EnFollow = add(EnFollow, '$');  // follow(s) = follow(s) + {$}
   }
   int theRightsSize = 0;
   std::string *theRights = new std::string[theRightsSize];// deja attribut partieDroite donc en peut utiliser en english;
   char *theLefts = new char[0];
   theLefts[0] = '\0';
   for (int i = 0; i < partieDroiteSize; i++) {
      if (partieDroite[i].find(symbol) !=
            std::string::npos) {  // npos une valeur retourner lorque functon fails;
         theRights = add(theRights, partieDroite[i], theRightsSize);
         theLefts = add(theLefts, partieGauche[i]);
         theRightsSize++;
      }
   }
   for (int i = 0; i < theRightsSize; i++) {
      if (alphaX(theRights[i], symbol)) {
         if (theLefts[i] != symbol) {
            Ftampon = follow(theLefts[i]);
            for (int j = 0; j < strlen(Ftampon); j++) {
               EnFollow = add(EnFollow, Ftampon[j]);
            }
         }
      } else {
         bool foundEpsilon = true;
         int symbolIndex = (int)theRights[i].find(symbol);
         if (isTerminal(theRights[i][symbolIndex + 1]))
            EnFollow = add(EnFollow, theRights[i][symbolIndex + 1]);
         else {
            for (int j = symbolIndex + 1;
                  j < theRights[i].length() && foundEpsilon; j++) {
               foundEpsilon = false;
               tampon = first(theRights[i][j]);
               for (int k = 0; k < strlen(tampon); k++) {
                  if (tampon[k] != '#') {
                     EnFollow = add(EnFollow, tampon[k]);
                  } else {
                     foundEpsilon = true;
                  }
               }
            }
            if (foundEpsilon) {
               Ftampon = follow(theLefts[i]);
               for (int k = 0; k < strlen(Ftampon); k++) {
                  EnFollow =
                     add(EnFollow, Ftampon[k]);  
               }
            }
         }
      }
   }
   return EnFollow;
}

