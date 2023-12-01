#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>



typedef void Objet;

typedef struct Noeud{
	char *data;	
	struct Noeud *suiv;
}Noeud;

typedef struct {
	Noeud *premier;
	Noeud *fin;
	int nb_elm;
}Pile;

Pile *create_pile(){
	Pile *P=(Pile*)malloc(sizeof(Pile));
	P->premier=NULL;
	P->fin=NULL;
	P->nb_elm=0;
	return P;
}

bool est_vide(Pile *P){
	if (P->nb_elm==0) return 1;
	return 0;
	//return P->premier==NULL;
}


void empile_pile(Pile *P,char *ob){
	Noeud *now=(Noeud*)malloc(sizeof(Noeud));
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

char *sommet(Pile *P){
	if(est_vide(P)){
		//printf("pile est vide");
		return NULL;
	}
	return P->premier->data;	
}

char *dipiler_pile(Pile *P){
	Noeud *now=P->premier;
	char *ob;
	if(!est_vide(P)){
		P->premier=P->premier->suiv;
		ob=now->data;
		free(now);
		//if(P->premier==NULL)	
		//	P->fin==NULL;
		P->nb_elm--;
		return ob;
	}
	//printf("pile est vide\n");
	return NULL;
}

void affiche_pile(Pile *P){
	if(est_vide(P)==0) printf("\n la pile est vide\n");
	else{
		Noeud *now=P->premier;
		printf("DEBUT ->  ");
		while(now!=NULL){
			printf("%s -> ",(char*)now->data);
			now=now->suiv;
		}
		printf(" FIN\n");
	}
}
