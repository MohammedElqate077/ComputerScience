#include<stdio.h>
#include<stdlib.h>

int main(){
	int N,i;

	printf("entrer dimention du tableau : ");
	scanf("%d",&N);

	int T[N];

	// saisire le tableau 

	for (i=0;i<N;i++){
		printf("entrer la valeur %d : ",i);
		scanf("%d",&T[i]);
	}

	int min=0,max=0;
	
	// determiner max et min

	for(i=1;i<N;i++){
		if (T[min]>T[i])
			min=i;
			
		if (T[max]<T[i])
			max=i;
			
	}
	printf("le max est %d et sa position est %d\nle min est %d et sa position est %d\n",T[max],max,T[min],min);
}
