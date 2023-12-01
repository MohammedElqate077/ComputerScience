#include<stdio.h>
#include<stdlib.h>

int *allouer(int N);
void saisire_mat(int *M,int N);
void affiche_mat(int *M,int N);
int  is_care_magic(int *M,int N);
int* produi_mat(int *M,int N);

void main (){
	int N;
	printf("\t *** donne la dimention de la matrice ***\n");scanf("%d",&N);

	int *T=allouer(N);
	
	printf("\t *** saisire les element de la matrice ***\n");
	saisire_mat(T,N);

	printf("\t *** les element de la matrice donnet ***\n");
	affiche_mat(T,N);
/*
	printf("\t *** resulta de produit de matrice  ***\n");
	r/int *T1=NULL;
	//T1=produi_mat(T,N);
	affiche_mat(produi_mat(T,N),N);
*/
	if(is_care_magic(T,N)==1)
		printf("matric care magic\n");
	else printf("matric non care magic\n");
}

int *allouer(int N){
	int *T=(int *)calloc(N*N,sizeof(int));
	if (T==NULL){ 
		printf("memoire non allouer");
		exit(0);
	}
	return T;
}

void saisire_mat(int *M,int N){
	int i,j;	
	for (i=0;i<N;++i)
		for(j=0;j<N;++j){
			printf("T[%d][%d]=",i,j);
			scanf("%d",(M+i*N+j));
		}
}

void affiche_mat(int *M,int N){
	int i,j;	
	for (i=0;i<N;++i){
		for(j=0;j<N;++j){
			printf(" %d ",*(M+i*N+j));
		}
		printf("\n");
	}
}

int is_care_magic(int *T,int N){
	int i,j,value,ligne=0,colone=0;
	for(value=i=j=0;i<N;++i,++j){
		value += *(T+i*N+j);
	}
	for(i=0;i<N;++i,ligne=0){
		for(j=0;j<N;++j){
			ligne += *(T+i*N+j);
		}
		if(value != ligne)
			return 0;	
	}
	for(j=0;j<N;++j,colone=0){
		for(i=0;i<N;++i){
			colone += *(T+i*N+j);
		}
		if(value != colone)
			return 0;	
	}
	return 1;
}
int* produi_mat(int *M,int N){
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
