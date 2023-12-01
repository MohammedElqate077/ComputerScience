#include<stdio.h>
#include<stdlib.h>

typedef enum{
	true=1, 
	false=0
}bool;

typedef void Objet;

typedef struct Noeud {
	Objet *data;	
	struct Noeud *suiv;	
}Noeud;

typedef struct {
	Noeud *premier;
	Noeud *fin;
	int nb_elm;
}File;

File *create_file(){
	File *F=(File*)malloc(sizeof(File));
	F->premier=NULL;
	F->fin=NULL;
	F->nb_elm=0;
	return F;
}

bool est_vide(File *F){
	return F->premier==NULL;
	//return F->nb_elm==0;
}

void emfiler_file(File *F,Objet *ob){
	Noeud *now=(Noeud*)malloc(sizeof(Noeud));
	now->data=(int*)ob;
	if(F->premier==NULL){
		now->suiv=F->premier;
		F->premier=now;
		F->fin=now;
	}else{
		now->suiv=NULL;
		F->fin->suiv=now;
		F->fin=now;
	}
	F->nb_elm++;
	return;
}

Objet *defiler_file(File *F){
	 Noeud *now=F->premier;
	 Objet *ob=F->premier->data;
	 if(!est_vide(F)){
		F->premier=F->premier->suiv;		
		free(now);
		now=NULL;
		F->nb_elm--;
		return ob;
	 }
	 else printf("la file est vide\n");
	 return NULL;
}

void affiche_file(File *F){
	if(est_vide(F))
		printf("la file est vide\n");
	else {
		Noeud *now=F->premier;	
		printf("DEBUT -> ");
		while(now!=NULL){
			printf("%d -> ",*(int*)now->data);
			now=now->suiv;
		}
		printf("FIN\n");
	}
	return;
}

int menu(){
	int c;
	system("clear");
        printf("\t [0]\t emfiler \n");
        printf("\t [1]\t defiler \n");
	printf("\t [2]\t la taille de File \n");
	printf("\t [3]\t le sommet de la File\n");
	printf("\t [4]\t affichage de File\n");
	printf("\t [5]\t is File vide ??\n");
	printf("\t [6]\t exit\n");
	printf("\n\t [6]\t entrer voter choi : ");
	scanf("%d",&c);
	return c;
}
