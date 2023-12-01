#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

typedef struct {
	int degre;
	int coeff;
}Objet;

typedef struct Monome{
	Objet data;
	struct Monome *suiv;
	struct Monome *prec;
}Monom;


typedef struct {
	Monom *premier;	
	Monom *fin;	
	int nb_mon;
}Poly;

typedef struct List_polyn {
	int num;
	Poly *P_po;		
	struct List_polyn *suiv;	
}List_poly;

int est_vide(Poly *po){
	if(po->nb_mon==0) return 1;
	return 0;
}

void initial_poly(Poly *po){
	po->premier=NULL;	
	po->fin=NULL;	
	po->nb_mon=0;	
}

Poly *create_poly(){
	Poly *po=(Poly*)malloc(sizeof(Poly));
	initial_poly(po);
	return po;
}

Monom *create_monom(){
	Monom *mo=(Monom*)malloc(sizeof(Monom));
	mo->data.degre=0;
	mo->data.coeff=0;
	mo->suiv=NULL;
	mo->prec=NULL;
	return mo;
}

Objet *create_objet(){
	Objet *ob=(Objet*)malloc(sizeof(Objet));
	ob->degre=0;
	ob->coeff=0;
	return ob;
}

Objet get_objet(){
	Objet ob;
	printf("degre:");scanf("%d",&ob.degre);
	printf("coeff:");scanf("%d",&ob.coeff);
	return ob;
}


void inser_tete_poly(Poly *po,Objet ob){
	Monom *mo=create_monom();
	mo->data=ob;
	if(po->premier==NULL){
		po->premier=mo;
		po->fin=mo;
	}
	else{
		mo->suiv=po->premier;
		po->premier->prec=mo;
		po->premier=mo;
	}
	po->nb_mon++;
}

void inser_fin_poly(Poly *po,Objet ob){
	Monom *mo=create_monom();
	mo->data=ob;

	if(po->premier==NULL){
		po->premier=mo;
		po->fin=mo;
	}
	else{
		po->fin->suiv=mo;
		mo->prec=po->fin;
		po->fin=mo;
	}
	po->nb_mon++;
}

void copy_poly(Poly *P,Poly *po){
	Monom *M=po->premier;
	Objet *ob=create_objet();
	while(M!=NULL){
		ob->degre=M->data.degre;
		ob->coeff=M->data.coeff;
		inser_fin_poly(P,*ob);
		M=M->suiv;
	}
	free(ob);
	ob=NULL;
}

void inser_dec_poly(Poly *po,Objet ob){
	//Monom *M=(Monom*)malloc(sizeof(Monom));
	//void *moo=po->premier;
	Monom *M=po->premier;
	//Objet ob;
	if(est_vide(po)){
		inser_tete_poly(po,ob);
		return;
	}
	while( M->suiv!=NULL && M->data.degre > ob.degre  ){
	//while( M->data.degre > ob.degre  ){if(M->suiv==NULL) break;	
		M=M->suiv;	
	}
	if(M->data.degre == ob.degre) {
		M->data.coeff += ob.coeff ;
		return;
	}
	if(M->prec==NULL)	{
		inser_tete_poly(po,ob);
		return;
	}
	if(M->suiv==NULL){
		inser_fin_poly(po,ob);
		return;
	}

	Monom *mo=create_monom();
	mo->data=ob;
	M->prec->suiv=mo;
	mo->prec=M->prec;
	M->prec=mo;
	mo->suiv=M;
	po->nb_mon++;
}

void suprimer_monom_poly(Poly *po,int degre){
	Monom *M=po->premier;	
	if(est_vide(po)){
		return;
	}
	int trouve=0;
	while(M!=NULL && !trouve ){
		if(M->data.degre==degre){
			if(M->suiv==NULL){
				po->fin=M->prec;
				po->fin->suiv=NULL;
			}
			else if(M->prec==NULL){
				po->premier=M->suiv;
				po->premier->prec=NULL;
			}
			else{
				M->suiv->prec=M->prec;
				M->prec->suiv=M->suiv;	
			}
			free(M);
			M=NULL;
			po->nb_mon--;
			trouve=1;
		}
		else M=M->suiv;
	
	}
}

void affiche_dec(Poly *po){
	Monom *M=po->premier;	
	if(est_vide(po)){
		return;
	}
	while(M!=NULL ){
		if(M->suiv!=NULL)
			printf(" %dX^%d +",M->data.coeff,M->data.degre);
		else 
			printf(" %dX^%d ",M->data.coeff,M->data.degre);

		M=M->suiv;
	}
	printf("\n");
}

void affiche_croi(Poly *po){
	Monom *M=po->fin;	
	if(est_vide(po)){
		return;
	}
	while(M!=NULL ){
		if(M->prec!=NULL)
			printf(" %dX^%d +",M->data.coeff,M->data.degre);
		else 
			printf(" %dX^%d ",M->data.coeff,M->data.degre);

		M=M->prec;
	}
	printf("\n");
}

void destruct_poly(Poly *po){
	Monom *M=po->premier;
	while(M->suiv!=NULL){
		free(M->prec);
		M->prec=NULL;
		M=M->suiv;
	}
	free(M);
	M=NULL;
	initial_poly(po);
}

///////////////////////////////////////////////////////////////

void multi_scal_poly(Poly *po,int scal){
	Monom *M=po->premier;
	while(M!=NULL){
		M->data.coeff *=scal;
		M=M->suiv;
	}
	return ;
}

void multi_monom_poly(Poly *po,Objet ob){
	Monom *M=po->premier;
	while(M!=NULL){
		M->data.degre +=ob.degre;
		M->data.coeff *=ob.coeff;
		M=M->suiv;
	}
	return ;
}

void some_poly(Poly *po,Poly *po_2){
	Monom *M=po_2->premier;

	while (M!=NULL){
			inser_dec_poly(po,M->data);
			M=M->suiv;
	}
	return ;
}

void sub_poly(Poly *po,Poly *po_2){
	Monom *M=po_2->premier;

	while (M!=NULL){
			M->data.coeff *=-1;
			inser_dec_poly(po,M->data);
			M=M->suiv;
	}
	return ;
}

Poly *prod_poly(Poly *po,Poly *po_2){
	Poly *PO=create_poly();
	Poly *PO_temp=create_poly();
	Monom *M=po->premier;

	copy_poly(PO,po);
	while (M!=NULL){
				copy_poly(PO_temp,po_2);

				if(M->data.degre==0){
					multi_scal_poly(PO_temp,M->data.coeff);
				}
				else multi_monom_poly(PO_temp,M->data);
				if(M->data.coeff > 0){
					some_poly(PO,PO_temp);
				}
				else if(M->data.coeff != 0){
					sub_poly(PO,PO_temp);
				}
				M=M->suiv;
				destruct_poly(PO_temp);
	}
	free(M);
	M=NULL;
	free(PO_temp);
	PO_temp=NULL;
	return PO;
}

///////////////////////////////////////////////////////////

int menu(){
	int choi;		
    printf("\t\t\t == MENU == \n\n");
    printf("\t 1  - crea une poly\n");
    printf("\t 2  - ajouter un monome \n");
    printf("\t 3  - suprimer un monome\n");
    printf("\t 4  - affiche le poly decroissant\n");
    printf("\t 5  - affiche le poly croissant\n");
    printf("\t 6  - suprimer un poly\n");
    printf("\t 7  - multiplication poly par un scalaire\n");
    printf("\t 8  - multiplication poly un monome\n");
    printf("\t 9  - somme de deux poly\n");
    printf("\t 10 - soustraction de deux poly\n");
    printf("\t 11 - multiplication de deux poly\n");
    printf("\t 12 - l'evaluation d'un poly\n");
    printf("\t 13 - affiche la liste des polys\n");
    printf("\t 14 - supriemer a liste des polys\n");
    printf("\t 0  - exit\n");
    //printf("\t \n");
    scanf("%d",&choi);
    return choi;
}	



int main(){
	int choi,FIN;
	int i,n;

	Poly *P;
	Objet ob;
	do{
		choi=menu();
		system("clear");
		printf("\n");
		switch (choi){
			case 1:
					P=create_poly();break;
			case 2:

					printf("enter F if exit\n");;//scanf("%c",&FIN);
					while((FIN!='F')){
					ob=get_objet();
					inser_dec_poly(P,ob);
					getchar();FIN=getchar();
					}break;
			case 3:
					ob=get_objet();
					suprimer_monom_poly(P,ob.degre);break;
			case 4:
					affiche_dec(P);
					stdin=freopen(NULL,"r",stdin);//getchar();// 2 getchar resolve the probleme
					getchar();break;

			case 5:
					//affiche_croi(P);getchar();getchar();break;
			case 6:
			case 7:
			case 9:
			case 10:
			case 11:
			case 12:
			case 13:
					printf("doner le num de poly a suprimer : "),scanf("%d",&n);
					//destruct_poly(P);break;
			default :
		}
		system("clear");
	}while(choi != 0);
	return 0;
}
