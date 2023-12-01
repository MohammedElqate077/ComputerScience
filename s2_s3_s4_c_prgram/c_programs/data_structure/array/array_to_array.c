#include<stdio.h>
#include<stdlib.h>

int mian (){
	int N,M;

	printf("entrer dimention du premier tableau : ");
	scanf("%d",N);
	printf("entrer dimention du 2ime tableau : ");
	scanf("%d",M);

	int A[N],B[M];

	int *p1,*p2;

	//saisire le tableau

	for(p1=A;p1<A+N;p1++){
		printf("entrer la valeur %ld : ",p1-A);
		scanf("%d",p1);
	}

	for(p2=B;p2<B+M;p2++){
		printf("entrer la valeur %ld : ",p2-B);
		scanf("%d",p2);
	}

	for(p2=B;p2<B+M;p2++){
		*p1=*p2;
		p1++;
	}
	N+=M;
	for(p1=A;p1<A+N;p1++){
		printf(" %d ",*p1);
		
	}
}


/*
#include<stdio.h>
#include<stdlib.h>

int main (){
	int N,M;

	printf("entrer dimention du premier tableau : ");
	scanf("%d",&N);
	printf("entrer dimention du 2ime tableau : ");
	scanf("%d",&M);

	int A[N],B[M];

	int i;

	//saisire le tableau
	printf("premier tablea\n");
	for(i=0;i<N;i++){
		printf("entrer la valeur %d : ",i);
		scanf("%d",&A[i]);
	}
	printf("2eme tableau\n");
	for(i=0;i<M;i++){
		printf("entrer la valeur %d : ",i);
		scanf("%d",&B[i]);
	}

	for(i=0;i<M;i++){
		*(A+N+i)=B[i];
	}
	N+=M;
	
	printf("le tableau resultat : \n");
	for(i=0;i<N;i++){
		printf("%d ",A[i]);
		
	}
	printf("\n");
}
*/