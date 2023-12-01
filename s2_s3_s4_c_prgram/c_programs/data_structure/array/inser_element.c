#include<stdio.h>
#include<stdlib.h>

int main(){
	int i,N,v;

	printf("entrer dimention du tableau : ");
	scanf("%d",&N);

	//N=N+1;

	int T[N];

	//saisire le tableau

	for (i=0;i<N;i++){
		printf("entrer la valeur %d : ",i);
		scanf("%d",&T[i]);
	}

	// trier le tableau croissant 

	for (i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			if (T[i]>T[j]){
				v=T[i];
				T[i]=T[j];
				T[j]=v;
			}
		}
	}

	// affichage du tableau avant l'insertion
	printf("avant l'insertion\n");
	printf("T[%d]={ ",N);
	for (i=0;i<N;i++){
		printf(" %d ",T[i]);
	}
	printf(" }\n");

	//inserstion du valeur avec tableau trie
	printf("entrer la valeur a inserser \n");
	scanf("%d",&v);
	
	i=N+=1;
	
	while(T[i-1]>v && i>0){
		T[i-1]=T[i-2];
		i--;
	}

	T[i]=v;
	//N++;


	


	// affichage du tableau apre insertion

	printf("tableau apre insertion\n");
	printf("T[%d]={ ",N);
	for (i=0;i<N;i++){
		printf(" %d ",T[i]);
	}
	printf(" }\n");

	return 0;
}
