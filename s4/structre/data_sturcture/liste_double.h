#include<stdio.h>
#include<stdlib.h>

typedef void Objet;

typedef struct Element{
	Objet *data;
	struct Element *suiv;
	struct Element *prec;
}Elem;

typedef struct{
	Elem *premier;
	Elem *fin;
	int nb_elm;
}List;

void inisiale_list(List *li){
	li->premier=NULL;
	li->fin=NULL;
	li->nb_elm=0;
	return;
}

List *crea_list(){
	List *li;
	li=(List *)malloc(sizeof(List));
	if(li==NULL){
		printf("allocation de la list FAILD");
		exit(0);
	}
	inisiale_list(li);
	return li;
}

int est_vide(List *li){ return li->nb_elm; }

Elem *create_elem(){ Elem *e=(Elem *)malloc(sizeof (Elem)); return e;}

void ajouter_tete_list(List *li,Objet *ob){
	Elem *nouveau=create_elem();

	nouveau->data=ob;
	nouveau->suiv=NULL;
	nouveau->prec=NULL;

	if(li->fin==NULL){
		li->premier=nouveau;
		li->fin=nouveau;
	}else{
		li->premier->prec=nouveau;
		nouveau->suiv=li->premier;
		li->premier=nouveau;
	}
	li->nb_elm++;
	return;
}

void ajouter_fin_list(List *li,Objet *ob){
	if (est_vide(li)) ajouter_tete_list(li,ob);return;

	Elem *nouveau=create_elem();	
	
	nouveau->data=ob;
	nouveau->suiv=NULL;
	nouveau->prec=li->fin;
	li->fin->suiv=nouveau;		
	li->fin=nouveau;	
	li->nb_elm++;
	return;	
}

void inser_preced_list(List *li,Elem *precedent,Objet *ob){
	if(precedent==NULL){
		ajouter_tete_list(li,precedent);
	}
	else if (li->fin==precedent){
		ajouter_fin_list(li,ob);
	}
	else{
	Elem *nouveau=create_elem();
	nouveau->data=ob;
	precedent->suiv->prec=nouveau;
	nouveau->suiv=precedent->suiv;
	nouveau->prec=precedent;
	precedent->suiv=nouveau;
	li->nb_elm++;	
	}
	return;
}

void supprimer(List *li,Objet *ob){
	Elem *e=li->premier;
	int trouve=0;
	while(e!=NULL && !trouve ){
		if(e->data=ob){
			if(e->suiv==NULL){
				li->fin=e->prec;
				li->fin->suiv=NULL;
			}
			else if(e->prec==NULL){
				li->premier=e->suiv;
				li->premier->prec=NULL;
			}
			else{
				e->suiv->prec=e->prec;
				e->prec->suiv=e->suiv;	
			}
			free(e);
			e=NULL;
			li->nb_elm--;
			trouve=1;
		}
		else e=e->suiv;
	
	}
}

