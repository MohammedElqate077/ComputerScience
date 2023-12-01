#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include "s4_ex.h"


#define maxnote 10

#define is_redoublement(a) (a?puts("oui"):puts("nom"))



typedef struct {
    int jour;
    char moi[10];
    int anne;
}La_date;

typedef struct {
    char nom[15];
    char prenon[15];
    La_date naissance;
    char formation[3];
    char redoublement;
    int td;
    int nb_note;
    float notes[maxnote];
    int note_valid;
}objet;

float moyenne_notes(objet *fi);

void lire_date(La_date *element){
    printf("    jour    : ");scanf("%d",&element->jour);
    printf("    moi : ");scanf(" %s",element->moi);
    printf("    anne : ");scanf("%d",&element->anne);

}

void lire_notes(float *notes,int *note_valid,int nb_note){
    *note_valid=0;
    int i=0;
    while (i<nb_note){
        printf("        note %d : ",i+1);scanf("%f",notes+i);
        if(*(notes+i) >= 10){
             (*note_valid)++;
        }
        i++;
    }
}

void ajoute_notes(objet *fi){
    if(fi->nb_note < maxnote)
    lire_notes(fi->notes,&fi->note_valid,fi->nb_note);
}

objet *lire_objet(objet *fi){
    printf("\n\n\t\t ** creation de la objet **\n\n");
    printf("    nom : ");fgets(fi->nom,15,stdin);//scanf("%s",fi->nom);
    printf("    prenon : ");fgets(fi->prenon,15,stdin);
    lire_date(&fi->naissance);
    printf("    formation : ");scanf("%s",fi->formation);
    printf("    group de td : ");scanf("%d",&fi->td);
    printf("    redoublement (o si oui n si non): ");scanf(" %c",&fi->redoublement);
    printf("    nb des notes (max %d) : ",maxnote);scanf(" %d",&fi->nb_note);
    ajoute_notes(fi);
    return fi;
}

void afobjet_notes(float *notes,int nb_note){
    int i=0;
    while (i<nb_note && nb_note < maxnote){
        printf("        note %d : %.2f\n",i+1,*(notes+i));
        i++;
    }
}
void ecrire_objet(objet *fi){
    char n_o;
    //float moyen=moyenne_notes(fi);
    printf("\n\n\t\t ** affichage de la objet **\n\n");

    printf("    nom : %s ",fi->nom);
    printf("    prenon : %s ",fi->prenon);
    printf("    date de naissance j/m/a : %d / %s / %d\n",fi->naissance.jour,fi->naissance.moi,fi->naissance.anne);
    printf("    formation : %s\n",fi->formation);
    printf("    group de td : %d\n",fi->td);
    printf("    redoublement : ");is_redoublement(fi->redoublement=='o');//?puts("oui"):puts("nom");
    printf("    nombre note valide %d\n",fi->note_valid);
    printf("    afobjet la moyen (o si oui ,n si nom) : ");scanf(" %c",&n_o);
    if( n_o=='o' || n_o=='O'){
        printf("        le moyen : %.2f\n",moyenne_notes(fi));
    }
    printf("    afobjet notes ou nom(o si oui ,n si nom) : ");scanf(" %c",&n_o);
    if( n_o=='o' || n_o=='O'){
        afobjet_notes(fi->notes,fi->nb_note);
    }
}

float moyenne_notes(objet *fi){
        int i=0;
        float some=0;
        while( i < maxnote ){
            some+=*((fi->notes)+i);
            i++;
        }
        return some/fi->nb_note;
}


int menu_choi(int choi){
        printf("\t\t\t == MENU == \n\n");
        printf("\t 1- crea une list\n");
        printf("\t 2- ajouter dans la list\n");
        printf("\t 3- ajouter en tete de la liste\n");
        printf("\t 4- inserer un element dans la liste\n");
        printf("\t 5- trie la liste la liste\n");
        printf("\t 6- recherche un element \n");
        printf("\t 7- suprimer un element\n");
        printf("\t 8- afobjet la liste\n");
        printf("\t 9- exit\n");
        //printf("\t \n");
        scanf("%d",&choi);
        return choi;
}







typedef objet objet;

typedef struct element{
     objet *data; 
    struct element *suivant;
}Element;


typedef struct {
    Element *premier;    
    Element *fin;
    int nb_elm;
}List;



List *crea_list();
void initial_list(List *li);
int estvide(List *li);
Element *crea_element();
void ajouter_tete_list(List *li,objet *ob);
void ajouter_fin_list(List *li,objet *ob);
void inser_precedent_list(List *li,Element *preced,objet *ob);
objet  *extra_tete_list(List *li);
List *suprimer_tete_list(List *li);
List *suprimer_fin_list(List *li);
objet recheche_element(List *li ,objet ob_search);
void afobjet_list(List *li);

List *crea_list(){
    List *li=(List *)malloc(sizeof(List));
    if (li==NULL) {
        printf("faild creation du list");
        exit(0) ;
	}
    initial_list(li);
    return li;
}

void initial_list(List *li){
    li->premier=NULL;
    li->fin=NULL;
    li->nb_elm=0;
}

int estvide(List *li){
    if(li->nb_elm==0) return 1;
    return 0;
}

Element *crea_element(){
    Element *e=(Element *)malloc(sizeof(Element));
    return e;
}
void ajouter_tete_list(List *li,objet *ob){
    Element *nouveau=crea_element();//(Element *)malloc(sizeof(Element));
    nouveau->data=lire_objet(ob);
    nouveau->suivant=li->premier;
    li->premier=nouveau;
    if(li->fin==NULL)
        li->fin=nouveau;
    li->nb_elm++;
}

void ajouter_fin_list(List *li,objet *ob){
    Element *nouveau=crea_element();//(Element *)malloc(sizeof(Element));
    if(li->premier==NULL)
        ajouter_tete_list(li,ob);
    else{
       nouveau->data=lire_objet(ob);
       nouveau->suivant=NULL;
       li->fin=nouveau; 
       li->nb_elm++;
    }
}

void inser_precedent_list(List *li,objet *ob){
    Element *preced;
    if(li->premier==NULL){
        ajouter_tete_list(li,ob);
    }
    else{
    Element *nouveau=crea_element();
    nouveau->data=lire_objet(ob); 
    nouveau->suivant=preced->suivant;
    preced->suivant=nouveau;
    li->nb_elm++;
    }
    if(preced->suivant==NULL){ //if(preced==li->fin)
        ajouter_fin_list(li,ob);
    }
}
/*
objet  *extra_tete_list(List *li){
    Element *extra=li->premier;
    if (!estvide(li)){
        li->premier=li->premier->suivant;
        li->nb_elm--;
    }
    return extra!=NULL?extra:NULL;
}
*/
List *suprimer_tete_list(List *li){
    Element *e=li->premier;
    if(estvide(li)) return li;
    if (!estvide(li)){
        li->premier=li->premier->suivant;
        free(e);e=NULL;
        if (li->premier==NULL)
            li->fin=NULL;
        li->nb_elm--;
    }
    return li;
}

List *suprimer_fin_list(List *li){
    Element *e=li->premier;
    if(estvide(li)) return li;
    if (li->nb_elm==1){
        li->nb_elm--;
        free(li);
        return NULL;
      }
    while(e->suivant->suivant!=NULL) e=e->suivant;
    free(e->suivant);
    e->suivant=NULL;
    li->fin=e;
    li->nb_elm--;
    return li;
    
}

/*
objet *recheche_element(List *li ,objet ob_search){
    int existe=0;// pour le return si il existe ou non
    objet *ob ;
    Element *current=li->premier; 
    while (current !=NULL && (!existe)){
        ob=current->data;
        existe=compare_data(*ob_search,*ob);//   int compare_data(objet *,objet *) pour comparaer les 2 data 
        current=current->suivant;
    }
    return existe?ob:NULL;
}
*/

void afobjet_list(List *li){
    Element *current=li->premier;
    while(current!=NULL){
        objet *ob=current->data;
        ecrire_objet(ob);//pour afobjet les info de data et la fonction afobjet les info ca depend de data;
        current=current->suivant;
    }
}

void principale(List *li){
    int choi=0;
    while( choi!=8){
        start:
        choi=menu_choi(choi);
        objet *ob;
        switch(choi){
            case 1 :
                li=crea_list();break; 
            case 2 :
                ajouter_fin_list(li,ob);break;
            case 3 :
                ajouter_tete_list(li,ob);break;
            case 4 :
                inser_precedent_list(li,ob);break;
            /*
            case 5 :
                li=trie_liste(li);break;
            case 6 :
                get_element(li);break;
            case 7 :
                suprimer_element(li);
            */
            case 8 :
                afobjet_list(li);break;
            case 9 :
                exit(0);
            default : 
                puts("le choi incorect : saisire le bon choi \f");
                goto start;
        }
    }
}