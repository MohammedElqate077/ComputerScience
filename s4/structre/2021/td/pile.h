#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>



typedef void Objet;

typedef struct Noeud{
	Objet *data;	
	struct Noeud *suiv;
}Noeud;

typedef struct {
	Noeud *premier;
	Noeud *fin;
	int nb_elm;
}Pile;

Pile *crea_pile(){
	Pile *P=(Pile*)malloc(sizeof(Pile));
	P->premier=NULL;
	P->fin=NULL;
	P->nb_elm=0;
	return P;
}

bool est_vide(Pile *P){
	return P->premier==NULL;
}

pile *insrer_tete_pile(Pile *P,ob0)

void empile_pile(Pile *P,Objet *ob){
	Noeud *now=(Noeud*)malloc(Noeud);
	now->data=ob;
	now->suiv=P->premier;
	P->premier=now;
	P->nb_elm++;
	if(P->fin==NULL){
		P->fin=now;
		P->fin->suiv=NULL;
	}
	return;

}

Objet *sommet(Pile *P){
	if(est_vide(P)==0) printf("pile est vide");

	return P->premier->data;	
}

Objet *dipiler_pile(Pile *P){
	Noeud *now=P->premier;
	Objet *ob;
	if(!est_vide(P)){
		P->premier=P->premier->suiv;
		ob=now->data;
		free(now);
		if(P->premier==NULL)	
			P->fin==NULL;
		P->nb_elm--;
	}
	return ob;
}

void affiche_pile(Pile *P){
	if(est_vide(P)==0) printf("\n la pile est vide\n");
	else{
		Noeud *now=P->premier;
		printf("DEBUT ->  ");
		while(now!=NULL){
			printf("%d -> ",now->data);
			now=now->suiv;
		}
		printf(" FIN\n");
	}
}
