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
	now->suiv=NULL;
	if(F->premier==NULL){
		now->suiv=F->premier;
		F->premier=now;
		F->fin=now;
	//	F->fin->suiv=NULL;
		return;
	}
	F->fin->suiv=now;
	F->fin=now;
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
