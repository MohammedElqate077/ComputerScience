#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define max(a,b) a>b?a:b

//typedef enum { true=1 , false=0 }bool;

typedef int Elem;
typedef struct Noeud *Pnoeud;

typedef struct Noeud{
	Elem val;
	Pnoeud fg;
	Pnoeud fd;

}Noeud;

typedef Noeud* Arb_bin;

Arb_bin create_vide_arb(){ return NULL; }

Arb_bin arbre_vide(){
	return NULL;
} 

bool est_vide(Arb_bin A){
	return A==NULL;
}


Pnoeud create_noeud(Elem e){
	Pnoeud P=(Pnoeud)malloc(sizeof(Noeud));
	P->val=e;	
	P->fg=NULL;
	P->fd=NULL;
	return P;
}


Arb_bin construire_arb(Noeud *r,Arb_bin G,Arb_bin D){
	if(!est_vide(r)){
		r->fg=G;
		r->fg=D;
	}
	return r;
}

Arb_bin create_arb_elem(Elem e,Arb_bin G,Arb_bin D){ 
	return construire_arb(create_noeud(e),G,D);
}

Noeud racine(Arb_bin A){
	if(est_vide(A))	{
		printf("ERROR : ARBRE vide !! \n");
		exit(0);
	}
	return *A;
}

Arb_bin fils_gauche(Arb_bin A){
	if(est_vide(A))	{
		printf("ERROR : ARBRE vide !!\n");
		exit(0);
	}
	return A->fg;
}


Arb_bin fils_droite(Arb_bin A){
	if(est_vide(A))	{
		printf("ERROR : ARBRE vide !!\n");
		exit(0);
	}
	return A->fd;
}


Elem contenu(Noeud N){
	return N.val;
}


int taille_arb(Arb_bin A){
	if (est_vide(A))
		return 0;
	else 
		return 1+taille_arb(A->fg)+taille_arb(A->fd);
}


bool est_feuille(Arb_bin A){
	return (A->fg==NULL && A->fd==NULL); // est_vide(A->fg) && est_vide(A->fd);
}

int nb_feuille(Arb_bin A){
	if (est_vide(A))
		return 0;
	if(est_feuille(A))
		return 1;
	else return nb_feuille(A->fg)+nb_feuille(A->fd);
}

int hauteur_arbre(Arb_bin A){
	if (est_vide(A)  || est_feuille(A))
		return 0;
	return 1+max(hauteur_arbre(A->fg),hauteur_arbre(A->fd));
}


bool appartien(Arb_bin A,Elem e){
	if(est_vide(A))
		return 0;
	if (A->val==e)
		return 1;
	return appartien(A->fg,e)+appartien(A->fd,e);
}



/*void detruire(Arb_bin A){
	if (est_vide(A)) return ;
	detruire(A->fg);
	detruire(A->fd);
	free(A);
	A=NULL;
	}
}*/
Arb_bin detruire(Arb_bin A){
	if (est_vide(A)) return NULL;
	if(est_feuille(construire_arb(A,detruire(A->fg),detruire(A->fd)))){
		printf(" %d",A->val);
		free(A);
		A=NULL;
		return A;
	}
}


bool  compare_arbre(Arb_bin A,Arb_bin B){
	if (est_vide(A)) {
		return est_vide(B);
	}
	else if(est_vide(B)) {
		return false;
	}
	else if(A->val != B->val){
		return false;
	}
	else return compare_arbre(A->fg,B->fg) * compare_arbre(A->fd,B->fd);
}


void infixe(Arb_bin A){
	if (est_vide(A)) return;

	infixe(A->fg);
	printf(" %d",A->val);
	infixe(A->fd);
}


void prefixe(Arb_bin A){
	if (est_vide(A)) return;

	printf(" %d",A->val);
	prefixe(A->fg);
	prefixe(A->fd);
}

void postfix(Arb_bin A){
	if (est_vide(A)) return;

	postfix(A->fg);
	postfix(A->fd);
	printf(" %d",A->val);
}

// verfier algorithem posible est faut;
void par_hauteur(Arb_bin A){
	if (est_vide(A)) return;

	printf(" %d",A->val);
	printf(" %d",A->fg->val);
	printf(" %d",A->fd->val);
	par_hauteur(A->fg);
	par_hauteur(A->fd);
}

bool comparer_arb(Arb_bin A,Arb_bin B){
	if(est_vide(A)) return est_vide(B);
	else{
		if(est_vide(B)) return false;
		else{
			if(A->val!=B->val) return false;
			else return comparer_arb(A->fg,B->fg)*comparer_arb(A->fd,B->fd);
		}
	}
}


// affichage {g,v,d} ces fils est vide affiche _;
void affiche_arb(Arb_bin A){
	if(est_vide(A)) printf("_");
	else{
		printf("{");
		affiche_arb(A->fg);
		printf(",%d,",A->val);
		affiche_arb(A->fd);
		printf("}");
	}
}
