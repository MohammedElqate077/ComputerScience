#include <stdio.h>
#include<stdlib.h>
typedef void objet;

typedef struct element{
     objet * data; 
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
objet *recheche_element(List *li ,objet *ob_search);
void affiche_list(List *li);
int compare_data(objet *ob_s,objet *ob);
void affiche_data(objet *ob);

List *crea_list(){
    List *li=(List *)malloc(sizeof(List));
    if (li==NULL) 
        printf("faild creation du list");
        exit(0) ;

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
    nouveau->data=ob;
    nouveau->suivant=li->premier;
    li->premier=nouveau;
    if(li->fin=NULL)
        li->fin=nouveau;
    li->nb_elm++;
}

void ajouter_fin_list(List *li,objet *ob){
    Element *nouveau=crea_element();//(Element *)malloc(sizeof(Element));
    if(li->premier=NULL)
        ajouter_tete_list(li,ob);
    else{
       nouveau->data=ob;
       nouveau->suivant=NULL;
       li->fin=nouveau; 
       li->nb_elm++;
    }
}

void inser_precedent_list(List *li,Element *preced,objet *ob){
    if(li->premier==NULL){
        ajouter_tete_list(li,ob);
    }
    else{
    Element *nouveau=crea_element();
    nouveau->data=ob; 
    nouveau->suivant=preced->suivant;
    preced->suivant=nouveau;
    li->nb_elm++;
    }
    if(preced->suivant==NULL){ //if(preced==li->fin)
        ajouter_fin_list(li,ob);
    }
}

objet  *extra_tete_list(List *li){
    Element *extra=li->premier;
    if (!estvide(li)){
        li->premier=li->premier->suivant;
        li->nb_elm--;
    }
    return extra!=NULL?extra:NULL;
}

List *suprimer_tete_list(List *li){
    Element *e=li->premier;
    if(estvide) return li;
    if (!estvide)
        free(e);
        li->premier=li->premier->suivant;
        if (li->premier==NULL)
            li->fin=NULL;
        li->nb_elm--;
    return li;
}

List *suprimer_fin_list(List *li){
    Element *e=li->premier;
    if(estvide) return li;
    if (li->nb_elm==1)
        free(li);
        li->nb_elm--;
        return NULL;
    while(e->suivant->suivant!=NULL) e=e->suivant;
    free(e->suivant);
    e->suivant=NULL;
    li->fin=e;
    li->nb_elm--;
    return li;
    
}

objet *recheche_element(List *li ,objet *ob_search){
    int existe=0;// pour le return si il existe ou non
    objet *ob ;
    Element *current=li->premier; 
    while (current !=NULL && (!existe)){
        ob=current->data;
        existe=compare_data(ob_search,ob);//   int compare_data(objet *,objet *) pour comparaer les 2 data 
        current=current->suivant;
    }
    return existe?ob:NULL;
}

void affiche_list(List *li){
    Element *current=li->premier;
    while(current!=NULL){
        objet *ob=current->data;
        affiche_data(ob);//pour affiche les info de data et la fonction affiche les info ca depend de data;
        current=current->suivant;
    }
}

int compare_data(objet *ob_s,objet *ob){}
void affiche_data(objet *ob){}
