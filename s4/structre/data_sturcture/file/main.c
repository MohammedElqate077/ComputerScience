#include "file.h"
#include<unistd.h>
int main()

{
    File* pi;int c;
    pi = create_file();
    printf("--------------------------------------------------\n");
    printf("\t *** Bonjour ,test sur les files ***\n");
    printf("--------------------------------------------------\n");
    printf("\t WAIT ... \n");sleep(1);
    do
    {
/*	system("clear");
        printf("\t [0]\t emfiler \n");
        printf("\t [1]\t defiler \n");
	printf("\t [2]\t la taille de File \n");
	printf("\t [3]\t le sommet de la File\n");
	printf("\t [4]\t affichage de File\n");
	printf("\t [5]\t is File vide ??\n");
	printf("\t [6]\t exit\n");
	printf("\n\t [6]\t entrer voter choi : ");
	scanf("%d",&c);
	//printf("\t WAIT ... \n");sleep(1);
*/
	    c=menu();
	    switch(c)
        {
            case 0:
		system("clear");
		printf("\t element a emfiler : ");
		int *i=(int*)malloc(sizeof(int));
		scanf("%d",i);
		emfiler_file(pi,i);break;
            case 1:
		system("clear");
		printf("\t element defiler %d",*(int*)defiler_file(pi));
		fflush(stdin);getchar();
		getchar();break;
            case 2:
		system("clear");
		printf("la taille de file est %d\n",pi->nb_elm);
		fflush(stdin);getchar();
		getchar();break;
            case 3:
		system("clear");
		//printf("le sommet de la file est %d\n",*(int*)sommet_file(pi));
		fflush(stdin);getchar();
		getchar();break;
            case 4:
		system("clear");
		printf("\t affichage de file \n  ");
		affiche_file(pi);
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


