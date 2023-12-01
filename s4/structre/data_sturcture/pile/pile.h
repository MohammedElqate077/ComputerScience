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
	//return P->nb_elm;
	return P->premier==NULL;
}

//Pile *insrer_tete_pile(Pile *P,ob0)

void empile_pile(Pile *P,Objet *ob){
	Noeud *now=(Noeud*)malloc(sizeof(Noeud));
//	(int*)now->data=(int*)ob;
	now->data=(int*)ob;
	now->suiv=P->premier;
	P->premier=now;
	P->nb_elm++;
	if(P->fin==NULL){
		P->fin=now;
		P->fin->suiv=NULL;
	}
	return;

}

Objet *sommet_pile(Pile *P){
	//if(est_vide(P)==0) printf("pile est vide");
	return P->premier->data;	
}

Objet *depiler_pile(Pile *P){
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
	else printf("la pile est vide");
	return ob;
}

void affiche_pile(Pile *P){
	if(est_vide(P)) {
		printf("\n la pile est vide\n");
//		printf("\n la pile  vide == %d \n",est_vide(P));
	}
	else{
		Noeud *now=P->premier;
		printf("DEBUT ->  ");
		while(now!=NULL){
			printf("%d -> ",*(int*)now->data);
			now=now->suiv;
		}
		printf(" FIN\n");
	}
}

int menu(){
	int c;
	system("clear");
        printf("\t [0]\t emPiler \n");
        printf("\t [1]\t dePiler \n");
	printf("\t [2]\t la taille de pile \n");
	printf("\t [3]\t le sommet de la pilei\n");
	printf("\t [4]\t affichage de Pile\n");
	printf("\t [5]\t is Pile vide ??\n");
	printf("\t [6]\t exit\n");
	printf("\n\t [6]\t entrer voter choi : ");
	scanf("%d",&c);
	//printf("\t WAIT ... \n");sleep(1);
	return c;	
	
}
