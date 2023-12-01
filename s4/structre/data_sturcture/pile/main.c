#include "pile.h"
#include<unistd.h>
int main()

{
    Pile* pi;int c;
    pi = crea_pile();
    printf("--------------------------------------------------\n");
    printf("\t *** Bonjour ,test sur les piles ***\n");
    printf("--------------------------------------------------\n");
    printf("\t WAIT ... \n");sleep(1);
    do
    {
	c=menu();
        switch(c)
        {
            case 0:
		system("clear");
		printf("\t element a empiler : ");
		int *i=(int*)malloc(sizeof(int));
		scanf("%d",i);
		empile_pile(pi,i);break;
            case 1:
		system("clear");
		printf("\t element depiler %d",*(int*)depiler_pile(pi));
		fflush(stdin);getchar();
		getchar();break;
            case 2:
		system("clear");
		printf("la taille de pile est %d\n",pi->nb_elm);
		fflush(stdin);getchar();
		getchar();break;
            case 3:
		system("clear");
		printf("le sommet de la pile est %d\n",*(int*)sommet_pile(pi));
		fflush(stdin);getchar();
		getchar();break;
            case 4:
		system("clear");
		printf("\t affichage de pile \n  ");
		affiche_pile(pi);
		fflush(stdin);getchar();
		getchar();break;
            case 5:
		system("clear");
		est_vide(pi)?puts("oui"):puts("nom");
		fflush(stdin);getchar();
		getchar();break;
	    case 6:
    		printf("\t WAIT ... \n");sleep(1);
    		system("clear");
		exit(0);
	    default :
           	 printf("Erreur de choix .\n");
		 sleep(1);break;
        }
    } while (c != 6);
   // exit(0);
    return 0;
}


