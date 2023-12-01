#include<stdio.h>
#include"s4_ex.h"
#include"s4_ex_list.h"


int menu_choi(int choi){
		printf("\t\t\t == MENU == \n\n");
		printf("\t 1- crea une list\n");
		printf("\t 2- ajouter dans la list\n");
		printf("\t 3- ajouter en tete de la liste\n");
		printf("\t 4- inserer un element dans la liste\n");
		printf("\t 5- trie la liste la liste\n");
		printf("\t 6- recherche un element \n");
		printf("\t 7- suprimer un element\n");
		printf("\t 8- affiche la liste\n");
		printf("\t 9- exit\n");
		//printf("\t \n");
		scanf("%d",&choi);
		return choi;
}

void principale(List *li){
	int choi=0;
	while( choi!=8){
		start:
		choi=menu_choi(choi);
		objet *ob;
		switch(choi){
			case 1 :
				li=crea_list();break; 
			case 2 :
				ajouter_fin_list(li,ob);break;
			case 3 :
				ajouter_tete_list(li,ob);break;
			case 4 :
				inser_precedent_list(li,ob);break;
			/*
			case 5 :
				li=trie_liste(li);break;
			case 6 :
				get_element(li);break;
			case 7 :
				suprimer_element(li);
			*/
			case 8 :
				affiche_list(li);break;
			case 9 :
				exit(0);
			default : 
				puts("le choi incorect : saisire le bon choi \f");
				goto start;
		}
	}
}