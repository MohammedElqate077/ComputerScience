#include<stdio.h>
#include<stdlib.h>

// **** avec pointeur : en commentaire fin du programme***
int main(){	
	int T[50],n,x,i,j;	
	
	
	printf("** dimension du tableau(max.50):");
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		printf("element %d :",i);
		scanf("%d",&T[i]);
	}	
	

	printf("** avant l'ilimination\n");

	printf("T[%d]={",n);
	for(i=0;i<n;i++){
		printf(" %d ",T[i]);
	}
	printf("}\n");

	for(j=i=0;i<n;i++){
		
		if(T[i]!=0){
			T[j]=T[i];
			j++;
		}
	}
	// nouvelle dimention de T
	//n=j;
	//edition du resultat
	printf("** apres l'ilimination\n");

	printf("T[%d]={",j);
	for(i=0;i<j;i++)
		printf(" %d ",T[i]);

	printf("}\n");
		
	return 0;


}

/*

	// **** avec pointeur ***

#include<stdio.h>
#include<stdlib.h>

int main(){	//declaration
	int A[50] ,n,x,*p1,*p2;	//pointeur d'aide
	
	printf("\n");
	printf("dimension du tableau(max.50):");
	scanf("%d",&n);
	//saisire le tableau
	for(p1=A;p1<A+n;p1++){
		printf("element %ld:",p1-A);
		scanf("%d",p1);
	}	
	printf("\n");	
	

	printf("\n");
	printf("avant l'ilimination\n");
	for(p1=A;p1<A+n;p1++){

		printf("%d ",*p1);
	
	// copier les element de p1 vers p2 et augmenter
	// p2 pour tous les elements differnts de x
	}
	printf("\n");

	for(p1=p2=A;p1<A+n;p1++){
		*p2=*p1;
		if(*p2!=0)
			p2++;
	
	}
	// nouvelle dimention de A
	n=p2-A;
	//edition du resultat
	printf("apres l'ilimination\n");
	for(p1=A;p1<A+n;p1++)
		printf("%d ",*p1);

	printf("\n\n");	
	return 0;


}

*/