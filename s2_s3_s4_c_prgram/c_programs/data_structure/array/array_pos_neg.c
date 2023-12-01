#include<stdio.h>
#include<stdlib.h>



void affich(int A[],int k){
	int i;
	

	printf("T[%d]={ ",k);
	for (i=0;i<k;i++){
		printf(" %d ",A[i]);
	}
	printf(" }\n");
}

void main (){

	int pos=0,neg=0,dim;
	

	printf("entrer dimention du tableau (max.50):");
	scanf("%d",&dim);

	int T[dim],Tpos[dim],Tneg[dim];

	for (int i=0;i<dim;i++){
		printf("entre l\'element %d:",i);
		scanf("%d",&T[i]);

		
		if (T[i]>0){
			Tpos[pos]=T[i];
			pos++;
		}
		else if (T[i]!=0){
			Tneg[neg]=T[i];
			neg++;
		}
	}


	printf("tableau donne\n");
	affich(T,dim);
	printf("tableau des postives\n");
	affich(Tpos,pos);
	printf("tableau des negatives\n");
	affich(Tneg,neg);


}
