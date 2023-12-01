#include<stdio.h>
#include<stdlib.h>
int main(){
	int m,M,nb;
	printf("entrer la valeur minimale de cette intervale\n");
	scanf("%d",&m);
	printf("ntrer la valeur maximale de cette intervale\n");
	scanf("%d",&M);
	printf("entrer un nombre quelqon\n");
	scanf("%d",&nb);
	if (nb>=m && nb<=M) printf("%d dans l'intervale [%d,%d]\n",nb,m,M);
	else printf("%d n'existe pas dans l'intervale [%d,%d]\n",nb,m,M);
}

/*
algorithme  nb_intervale
variables	m,M,nb 		:reel

debut
		ecrire("entrer la valeur minimale de cette intervale")
		lire(m)
		ecrire("entrer la valeur maximale de cette intervale")
		lire(M)
		ecrire("entrer un nombre quelqon")
		lire(nb)
		si(nb>=m et nb<=M) alors
			ecrire (nb,"dans 'intervale [",m," ",M"]")
		sinon
			ecrire (nb,"n'est pas dans 'intervale [",m," ",M"]")
		finsi
fin-
*/