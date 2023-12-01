#include"parti2.h"

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
