#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int Elem;
typedef struct noeud *Pnoeud;

typedef struct noeud{
	Elem val;
	Pnoeud fg;
	Pnoeud fd;

}Noeud;

typedef Noeud *Arb_bin;
typedef Noeud *Arb_bin_rech;

Arb_bin create_arb(){ return NULL; }
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

Noeud racine(Arb_bin A){
	if(est_vide(A))	{
		printf("ERROR : ARBRE vide !! \n");
		exit(-1);
	}
	return *A;
}

Arb_bin fils_gauche(Arb_bin A){
	if(est_vide(A))	{
		printf("ERROR : ARBRE vide !!\n");
		exit(-1);
	}
	return A->fg;
}


Arb_bin fils_droite(Arb_bin A){
	if(est_vide(A))	{
		printf("ERROR : ARBRE vide !!\n");
		exit(-1);
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


bool appartien_arb(Arb_bin A,Elem e){
	if(est_vide(A))
		return 0;
	if (A->val==e)
		return 1;
	return appartien_arb(A->fg,e)+appartien_arb(A->fd,e);
}

bool recherche_arb_rech(Arb_bin_rech A,Elem e){
	if(est_vide(A))		
		return false;
	if (A->val==e)
		return true;
	if (A->val>e)
		return recherche_arb_rech(A->fg,e);
	if (A->val<e)
		return recherche_arb_rech(A->fd,e);
}

Arb_bin_rech inserer_arb_rech(Arb_bin_rech A,Elem e){
	if(est_vide(A))	{
		Pnoeud racine=create_noeud(e);//return create_noeud(e);
		return construire_arb(racine,NULL,NULL); //ca depont initialisation si ce fait ds la creation de noeud;

	}
	if(A->val>e)
		return construire_arb(A,fils_gauche(A),inserer_arb_rech(fils_droite(A),e));
		// construire_arb(A,A->fg,inserer_arb_rech(A->fd,e));
	if(A->val<e)
		return construire_arb(A,inserer_arb_rech(fils_gauche(A),e),fils_droite(A));
		// construire_arb(A,inserer_arb_rech(A->fg,e),A->fd);
}

Pnoeud element_max(Arb_bin_rech A){
	if(est_vide(fils_droite(A))==true)
		return A;
	else
		return element_max(A->fd);
}


Pnoeud element_min(Arb_bin_rech A){
	if(est_vide(fils_gauche(A))==true)
		return A;
	else
		return element_min(A->fg);
}

Arb_bin_rech suprimer_max(Arb_bin_rech A){
	if(A->fd==NULL)
		return A->fg;
	else
		return construire_arb(A,fils_gauche(A),suprimer_max(fils_droite(A)));
}


Arb_bin_rech suprimer_min(Arb_bin_rech A){
	if(A->fg==NULL)
		return A->fd;
	else
		return construire_arb(A,suprimer_min(A->fg),A->fd);
}

Arb_bin_rech suprimer_arb_rech(Arb_bin_rech A,Elem e){
	if(est_vide(A))
		return A;
	if(A->val>e){
		construire_arb(A,A->fg,suprimer_arb_rech(A->fd,e));
	}
	else if(A->val<e){
		construire_arb(A,suprimer_arb_rech(A->fg,e),A->fd);
	}
	else {
		construire_arb(element_max(A->fg),suprimer_max(A->fg),A->fd);
			
	}
}

bool est_arb_bin_rech(Arb_bin_rech A){
	if(est_vide(A))
		return true;
	else
		return (A->val>A->fd->val && A->val<A->fg->val && est_aarb_bin_rech(A->fg) && est_aarb_bin_rech(A->fd));

}
