#include<stdio.h>
#include<stdlib.h>

int main(){
	int T[50][50],N,M,i,j;
	long int some=0;


	printf("entrer nb de ligne : ");
	scanf("%d",&N);
	printf("entrer nb de colone : ");
	scanf("%d",&M);

	// saisire le tableau

	for (i=0;i<N;i++){
		for (j=0;j<M;j++){
			printf("entrer la valeur T[%d][%d] : ",i,j);
			scanf("%d",&T[i][j]);
			some+=T[i][j];
		}
	}

	// afficheage du tableau et la somme de ces valeures
	printf("le donne");
	for (i=0;i<N;i++){
		for (j=0;j<M;j++){
			printf(" %d\t",T[i][j]);
		}
		printf("\n");
		
	}

	printf("la some des element de tableau est %d\n",some);

	return 0;
}
