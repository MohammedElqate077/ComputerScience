#include<stdio.h>
#include<stdlib.h>


void main(){
	
	int i=0,dim,temp;

	printf("entreer dimention du tableau (max.50):");
	scanf("%d",&dim);

	int T[dim];

	while(i<dim){
		printf("entrer l\'element %d:",i);
		scanf("%d",&T[i]);
		i++;
	}

	printf("tableau donne\n");
	printf("T[%d]={",dim);
	for(i=0;i<dim;i++){
		printf(" %d ",T[i]);
	}

	for(int j=dim-1,i=0;i<=j;i++,j--){
		temp=T[i];
		T[i]=T[j];
		T[j]=temp;
	}

	printf("}\ntableau resultat\n");
	printf("T[%d]={",dim);

	for(i=0;i<dim;i++){
		printf(" %d ",T[i]);
		
		
	}
	printf("}\n");

}
