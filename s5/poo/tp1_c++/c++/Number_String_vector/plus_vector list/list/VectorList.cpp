#include <iostream>
#include "VectorList.hpp"
#include "String.hpp"


VectorL::VectorL() {  // ()default;
  sizeVectorL = 0;   // = 0;
}

VectorL::VectorL(int size) {
   sizeVectorL = 0;
  for(int i = 1; i <= size; ++i)
     this->add();
}

/*VectorSt *VectorL::add(){
   VectorSt *temp = vecteur;
   if (sizeVectorL > 1) {
      while(temp->suiv != nullptr){ // or use getVect;
          temp = temp->suiv;
       }
       temp->suiv = new VectorSt;
       temp->suiv->prev = temp;
       temp = temp->suiv; // for return;
       temp->suiv = nullptr;
  }else {
    vecteur = new VectorSt; 
    temp = vecteur;
  }
   sizeVectorL++;
  return temp;
}*/


/*VectorSt *VectorL::add(){
   VectorSt *temp ;
   if ((temp = getVect(sizeVectorL)) != nullptr) {
       temp->suiv = new VectorSt;
       temp->suiv->prev = temp;
       temp = temp->suiv; // for return;
       temp->suiv = nullptr;
  }else {
    vecteur = new VectorSt; 
    temp = vecteur;
  }
  sizeVectorL++;
  return temp;
}*/

VectorSt *VectorL::add(){
   VectorSt *temp ;
  if (sizeVectorL == 0) {
    vecteur = new VectorSt; 
    temp = vecteur;
  }else if ((temp = getVect(sizeVectorL)) != nullptr && temp->suiv == nullptr) {
       temp->suiv = new VectorSt;
       temp->suiv->prev = temp;
       temp = temp->suiv; // for return;
       //temp->suiv = nullptr; not nesseary difined in constractor
  }
  sizeVectorL++;
  return temp;
}

void VectorL::add(String element) {
  VectorSt *temp = this->add() ;
  *temp->value = element;
}

void VectorL::add(int element) {
  String *temp = new String(element);
  this->add(*temp);
  delete temp;
}

void VectorL::add(double element) {
  String *temp = new String(element);
  this->add(*temp);
  delete temp;
}

void VectorL::add(char element) {
  String *temp = new String(element);
  this->add(*temp);
  delete temp;
}

void VectorL::add(VectorL element) {
  for (int i = 1; i <= element.sizeVectorL; ++i) {
     if(element.vecteur->value == NULL)
        this->add();
     else 
        this->add(*element.vecteur->value);
  }
}


VectorSt *VectorL::getVect(int index) {
   VectorSt *temp = vecteur;
   int i = 1;
   while( i < index && temp->suiv != nullptr){
       temp = temp->suiv;
       i++;
    }
   if(i == index)
      return temp;
   else
      return nullptr;
}

String VectorL::get(int index) {
   VectorSt *temp = getVect(index);
   if(temp == nullptr);
   else return *temp->value;
}

void VectorL::set(int index, String element) {
   //if(index >= sizeVectorL)
   VectorSt *temp ;
   if (index <= sizeVectorL && (temp = getVect(index)) != nullptr) 
      *temp->value = element;
   else
      std::cout << "this index must be under size of vector" << std::endl;
}


String VectorL::remove(int index) {
  String returnString;
  VectorSt *temp ;
  if(index == 1){
     temp = vecteur;
     vecteur->suiv->prev = nullptr;
     returnString = *vecteur->value;
     vecteur = vecteur->suiv;
     delete temp;
  }
  else if ((temp = getVect(index)) != nullptr) {
     if(temp->suiv == nullptr){
         temp->prev->suiv = nullptr; 
         returnString = *temp->value;
         delete temp->prev->suiv ; 
     }
     else {
      temp->suiv->prev = temp->prev; 
      temp->prev->suiv = temp->suiv;
      returnString = *temp->value;
      delete temp;
     }
  }
  sizeVectorL--;
  return returnString;
}

int VectorL::getIndex(String element) {
   int i = 1;
  bool nonExist = true;
  VectorSt *temp = vecteur;
  while (i <= sizeVectorL && nonExist) {
    if (Strcmp(*temp->value, element) == 0) {
      nonExist = false;
    }
    ++i;
    temp = temp->suiv;
  }
  if (nonExist == false)
    return i;
  else
    return -1;
}

int VectorL::size() { return sizeVectorL; }

void VectorL::print() {
  int i = 1;
  VectorSt *temp = vecteur;
  while ( i <= sizeVectorL && temp->value != nullptr){
    (*temp->value).print();
    temp = temp->suiv;  
    i++;
   }
}

int isDoubleInt(char *value) {
  int i = 0;
  int digit = 1;
  int virgule = 0;
  if (value[i] == '-') {
    ++i;
  }
  while (value[i] != '\0') {
    if (value[i] == '.') virgule++;
    if ((virgule == 2) && !isdigit(value[i])) {
      digit = 0;
      break;
    } else
      ++i;
  }
  if (digit && virgule == 1)
    return 1;
  else if (digit)
    return 0;
  else
    return -1;
}

double *VectorL::getDoubleVectorL() {
   VectorSt * temp = vecteur;
  int j = 0;
  double *tabReal = new double[sizeVectorL];
  for (int i = 1; i <= sizeVectorL; i++) {
    if (isDoubleInt(temp->value->get()) == 1) { // (*temp->value).get();
      tabReal[j] = (double)atof(temp->value->get());
      j++;
    }
    temp = temp->suiv;
  }
  tabReal = (double *)realloc(tabReal, j * sizeof(double));
  return tabReal;
}
int *VectorL::getIntVectorL() {
   VectorSt * temp = vecteur;
  int *tabInt = new int[sizeVectorL];
  int j = 0;
  for (int i = 0; i < sizeVectorL; i++) {
    if (isDoubleInt(temp->value->get()) == 0) {
      tabInt[j] = (int)atoi(temp->value->get());
      j++;
    }
    temp = temp->suiv;
  }
  tabInt = (int *)realloc(tabInt, j * sizeof(int));
  return tabInt;
}
