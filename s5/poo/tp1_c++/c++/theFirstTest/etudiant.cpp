#include <iostream>
#include <string.h>

using namespace std;

void copyNotes(int *tabNotes, int *tabNotes2, int &nbNotes){
    for (int i = 0; i < nbNotes; ++i)
        tabNotes[i] = tabNotes2[i];
}

class Etudiant{
private:
    int matricule;
    string nom;
    int nbNotes;
    float *tabNotes;
    static int n;

public:
    Etudiant();
    Etudiant(string nom, int nbNotes);
    Etudiant(const Etudiant& etud);
    string getNom();
    int getMatricule();
    int getnbNotes();
    float* gettabNotes();
    void setNom(const string& );
    void setMatricule();
    void setNbNotes(int);
    //void settabNotes(int*);
    void saisire();
    void affiche();
    float moyen();
    bool admis();
    bool comparer(Etudiant& etud2);
    ~Etudiant() { ;
        delete [] tabNotes;
        cout << "Etudiant " << nom << " has been deleted" << endl; 
    }
};

Etudiant::Etudiant(){
    cout << "Etudiant has been created" << endl;
    matricule = 0;
    nom = "";
    nbNotes = 0;
    tabNotes = new float [nbNotes];
}

Etudiant::Etudiant(string nom, int nbNotes){
    //Etudiant();
    ++n;
    this->nom = nom;
    this->matricule = n;
    this->nbNotes = nbNotes;
    tabNotes = new float[nbNotes];
}

Etudiant::Etudiant(const Etudiant& etud){
    nom = etud.nom;
    matricule = etud.matricule;
    nbNotes = etud.nbNotes;
    tabNotes = new float [nbNotes];
    //copyNotes(tabNotes, etud.tabNotes, nbNotes);
    for (int i = 0; i < nbNotes; ++i)
        tabNotes[i] = etud.tabNotes[i];
}

string Etudiant::getNom(){return nom;};
int Etudiant::getMatricule(){return matricule;};
int Etudiant::getnbNotes(){return nbNotes;};
float* Etudiant::gettabNotes(){return tabNotes;};

void Etudiant::setNom(const string& nom){this->nom = nom;}
void Etudiant::setMatricule(){ ++n ; matricule = n;}
//void Etudiant::setMatricule(int matricule){this->matricule = matricule;}
void Etudiant::setNbNotes(int nbNotes){this->nbNotes = nbNotes;}
//void Etudiant::settabNotes(int* tabNotes){ copyNotes(this->tabNotes,tabNotes,this->nbNotes); }


void Etudiant::saisire(){
    //tabNotes = new float[nbNotes];
    cout << "\nsaisire tabNotes " << nom << " " << matricule << endl;
    for(int i = 0 ;i < nbNotes; ++i){
        cout << "doner la note " << i+1 << " : ";
        cin >> tabNotes[i];
    }
    cout << endl;
}
//void Etudiant::affiche(Etudiant& etud){
void Etudiant::affiche(){
    cout << "matricule : " << matricule << endl;
    cout << "nom : " << nom << endl;
    cout << "nombre de note : " << nbNotes << endl;
    cout << "notes : ";
    for (int i = 0 ;i < nbNotes ;++i)
        cout << tabNotes[i] << " ";
    cout << "\nmoyen : " << moyen() << "\t--->\tadmis : " << admis() << "\n" << endl;

    }
//float Etudiant::moyen(Etudiant& etud){
float Etudiant::moyen(){
    float some = 0;
    for (int i = 0 ;i < nbNotes ;++i)
        some += tabNotes[i];
    return some/nbNotes;
}

bool Etudiant::admis(){
    return moyen() > 10 ;
    //return moyen() > 10 ? true : false;
}

bool Etudiant::comparer(Etudiant& etud2){
    return moyen() == etud2.moyen() ;
    //return moyen() == etud2.moyen() ? true : false ;
}

int Etudiant::n = 0;

int main(){
    static Etudiant etud1;//,etud1("mehdi",2,5);
    etud1.setNom("ayoub");
    etud1.setMatricule();
    etud1.setNbNotes(3);
    etud1.saisire();
    Etudiant etud2("mehdi",5);
    etud2.saisire();
    Etudiant etud3 = etud2;

    etud3.setNom("youssef");
    etud3.setMatricule();

    etud1.affiche();
    etud2.affiche();
    etud3.affiche();
    return 0;
}
