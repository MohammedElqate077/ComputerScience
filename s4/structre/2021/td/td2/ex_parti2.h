#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include"liste_simple.h"

typedef	struct Participant {
	char nom[20];	
	char prenom[30];	
	int dejeune;//0=nom,1=oui
	int dinne;//0=nom,1=oui
	int hotele;//1=pas hotel,2=2etoile,3=3etoile
	int seul;	//0=nom,1=oui
	char tele[20];	
	struct Participant *suiv;
}Part;


typedef struct{
	Part *premier;
	Part *fin;
	int nb_part;
}List;

int estvide(List *li){
    if(li->nb_part==0) return 1;
    return 0;
}

struct Participant *alouer_part(){
	Part *P=(Part*)malloc(sizeof(Part));
	P->suiv=NULL;
	return P;
}

void ajouter_tete_list(List *li,Part *P){
    P->suiv=li->premier;
    li->premier=P;
    if(li->fin=NULL)
        li->fin=P;
    li->nb_part++;
}

void ajouter_fin_list(List *li,Part *P){
    if(li->premier=NULL)
        ajouter_tete_list(li,P);
    else{
       P=P;
       P->suiv=NULL;
       li->fin=P; 
       li->nb_part++;
    }
}

void ajouter_precedent_list(List *li,Part *preced,Part *P){
    if(li->premier==NULL){
        ajouter_tete_list(li,P);
    }
    else{
    P->suiv=preced->suiv;
    preced->suiv=P;
    li->nb_part++;
    }
    if(preced->suiv==NULL){ //if(preced==li->fin)
        ajouter_fin_list(li,P);
    }
}


void saisie_part(struct Participant *P){
	printf("nom:");fflush(stdin);scanf("%s",P->nom);
	printf("prenom:");fflush(stdin);scanf("%s",P->prenom);
	printf("dejeune:");fflush(stdin);scanf("%d",P->dejeune);
	printf("dinne:");fflush(stdin);scanf("%d",P->dinne);
	printf("hotele:");fflush(stdin);scanf("%d",P->hotele);
	printf("seul:");fflush(stdin);scanf("%d",P->seul);
	printf("telephone:");fflush(stdin);scanf("%s",P->tele);

}
/*Part *search_part(List *li,Part *P){
	if(li->premier==NULL){
		return NULL;
	}
	else{
		Part *curr=li->premier;
		while(curr!=NULL){
			if(strcmp(curr->nom,P->nom)==0)
				if(strcmp(curr->tele,P->tele)==0) return curr;
			else curr=curr->suiv;
		}
	}
	return NULL;
}*/
Part *search_part(List *li,Part *P){//on utilse curr->suiv pour l'adress puor suprimer partculiler
	if(li->premier==NULL){
		return NULL;
	}
	else{
		Part *curr=li->premier;

		if(strcmp(curr->nom,P->nom)==0 && strcmp(curr->tele,P->tele)==0) return curr;

		while(curr!=NULL ) {
			if(strcmp(curr->suiv->nom,P->nom)==0 && strcmp(curr->suiv->tele,P->tele)==0){
				return curr;	
			}
			curr=curr->suiv;
			if(curr==NULL) break;
		}	
	}
	return NULL;
}

List* insere_part(List *li,Part *P){
	Part *curr=li->premier;
	if(li->premier==NULL  || (strcmp(curr->nom,P->nom)>0)){
		ajouter_tete_list(li,P); 
	}
	else{
		while(curr->suiv!=NULL && strcmp(curr->suiv->nom,P->nom)<0) 
			curr=curr->suiv;

		if(curr->suiv==NULL) 
			ajouter_fin_list(li,P);
		else if(strcmp(curr->suiv->tele,P->tele)!=0)
			ajouter_precedent_list(li,curr,P);
	}

	return li;
}

void nb2_etoile(List *li){
	Part *P=li->premier;	
	while(P!=NULL){
		if(P->hotele==2){
			printf("%s\t%s\n",P->nom,P->prenom);
		}
		P=P->suiv;
	}
}

void nb_dejeune(List *li){
	Part *P=li->premier;	
	int nb=0;
	while(P!=NULL){
		if(P->dejeune==1){
			nb++;
			if(P->seul==0)
				nb++;
		}
		P=P->suiv;
	}
	printf("nb_dejeune : %d\n",nb);
}

float montaon(Part *P){
	int total=0;
	if(P->dejeune==1) total+=15;
	if(P->dinne==1) total+=35;
	if(P->seul==0) total*=2;
	if(P->hotele==2) total+=75;
	if(P->hotele==3) total+=100;
	return total;
}
List *suprimer_tete_list(List *li){
    Part *e=li->premier;
    if(estvide) return li;
    if (!estvide)
        li->premier=li->premier->suiv;
        free(e);
        e=NULL;
        if (li->premier==NULL)
            li->fin=NULL;
        li->nb_part--;
    return li;
}

List *suprimer_fin_list(List *li){
    Part *e=li->premier;
    if(estvide) return li;
    if (li->nb_part==1)
        free(li);
        li->nb_part--;
        return NULL;
    while(e->suiv->suiv!=NULL) e=e->suiv;
    free(e->suiv);
    e->suiv=NULL;
    li->fin=e;
    li->nb_part--;
    return li;
    
}

void suprimer_apre_precedent(List *li,Part *prec){
	Part *e;
	if(li->premier==prec)
		suprimer_tete_list(li);
	else if(prec==li->fin){
		suprimer_fin_list(li);
	}
	else{
		e=prec->suiv;
		prec->suiv=e->suiv;
		free(e);
		e=NULL;
	}

	return;
}

void suprimer_part(List *li,Part *P){
	Part *curr=li->premier;
	Part *exist=search_part(li,P);
	if(exist==NULL) return;
	else suprimer_apre_precedent(li,exist);
}

List* suprimer_list(List *li){
	Part *curr=li->premier;

	while(curr!=NULL){
			suprimer_tete_list(li);
			curr=li->premier;
	}
	return li;
}


