#include<stdio.h>
#include<stdlib.h>
#include"arbre_bin.h"

typedef Noeud *Arb_bin_rech;


bool recherche_arb_rech(Arb_bin_rech A,Elem e){ // if you want return sous arbre e use type of Arb_bin_rech
	if(est_vide(A))		
		return false;  //return NULL;
	if (A->val==e)
		return true;  // return A;
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
	if(A->val < e)
		return construire_arb(A,fils_gauche(A),inserer_arb_rech(fils_droite(A),e));
		// construire_arb(A,A->fg,inserer_arb_rech(A->fd,e));
	else 	//if(A->val > e)
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
	if(A->fg==NULL && A->fd==NULL)	{
		return NULL;
	}
	else if(A->fg!=NULL && A->fd==NULL)
		return A->fg;
	else
		return construire_arb(A,fils_gauche(A),suprimer_max(fils_droite(A)));
}


Arb_bin_rech suprimer_min(Arb_bin_rech A){
	if(A->fg==NULL && A->fd==NULL)	{
		return NULL;
	}
	else if(A->fg==NULL && A->fd!=NULL)
		return A->fd;
	else
		return construire_arb(A,suprimer_min(A->fg),A->fd);
}

Arb_bin_rech suprimer_arb_rech(Arb_bin_rech A,Elem e){
	if(est_vide(A))
		return A;
	if(A->val<e){
		construire_arb(A,A->fg,suprimer_arb_rech(A->fd,e));
	}
	else if(A->val>e){
		construire_arb(A,suprimer_arb_rech(A->fg,e),A->fd);
	}
	else {
		construire_arb(element_max(A->fg),suprimer_max(A->fg),A->fd);
		//construire_arb(element_min(A->fd),A->fg,suprimer_max(A->fd)); // ca depent votre choi soit min_fd ou max_fg;
			
	}
}

