#include<stdio.h>
#include<stdlib.h>

void** saisire_mat(int **M,int N);
void affiche_mat(int **M,int N);
int** produi_mat(int **M,int N);

void main (){
	int N;
	printf("\t *** donne la dimention de la matrice ***\n");scanf("%d",&N);

	int **T=(int **)calloc(N,sizeof(int));
	if (T==NULL){ 
		printf("memoire non allouer");
		exit(0);
	}
	
	printf("\t *** saisire les element de la matrice ***\n");
	saisire_mat(T,N);

	printf("\t *** les element de la matrice donnet ***\n");
	affiche_mat(T,N);

	printf("\t *** resulta de produit de matrice  ***\n");
	int *T1=NULL;
	T1=produi_mat(T,N);
	affiche_mat(T1,N);
}

void** saisire_mat(int **M,int N){
	int i,j;	
	for (i=0;i<N;++i)
		for(j=0;j<N;++j){
			printf("T[%d][%d]=",i,j);
			scanf("%d",(*M+i*N+j));
		}
}

void affiche_mat(int **M,int N){
	int i,j;	
	for (i=0;i<N;++i){
		for(j=0;j<N;++j){
			printf(" %d ",*(M+i*N+j));
		}
		printf("\n");
	}
}

int** produi_mat(int **M,int N){
	int i,j;	
	int *T=(int *)calloc(N*N,sizeof(int));
	if (T==NULL){ 
		printf("memoire non allouer");
		exit(0);
	}
	for (i=0;i<N;++i)
		for(j=0;j<N;++j)
			for(int k=0;k<N;++k)
				*(T+i*N+j)+=*(M+i*N+k) * *(M+k*N+j);
	
	return T;
}
