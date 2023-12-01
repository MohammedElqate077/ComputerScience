#include<stdio.h>
#include<stdlib.h>
#include"s4_ex.h"
#include"s4_ex_list.h"

int main(){
	int choi=-1;
	while(choi!=){
		printf("\t\t\t == MENU == \n\n");
		printf("\t 2- ajouter dans la list\n");
		printf("\t 3- ajouter en tete de la liste\n");
		printf("\t 4- ajouter apre un precedent de la liste\n");
		printf("\t 5- ajouter en fin de la liste\n");
		printf("\t 6- recherche un element \n");
		printf("\t 7- suprimer un element\n");
		printf("\t 8- affiche la liste\n");
		printf("\t 9- exit\n");
		//printf("\t \n");
		scanf("%d",choi);
	}
	printf()
	fiche fi;
	printf("\n\n\t\t **** creation de la fiche ****\n\n");
	lire_fiche(&fi);
	printf("\n\n\t\t **** affichage de la fiche ****\n\n");
	ecrire_fiche(fi);

}
