


#include<stdio.h>
#include<stdlib.h>

int *allouer(int N);
int *remplire_mat(int N);
void affiche_mat(int *M,int N);
long long int combin(long long int  n , long long int p);

void main (){
	int N;
	printf("entre dimention du matrice : ");scanf("%d",&N);
	affiche_mat(remplire_mat(N),N);

}

int *allouer(int N){
	int *T=(int *)calloc(N*N,sizeof(int));
	if (T==NULL){ 
		printf("memoire non allouer");
		exit(0);
	}
	return T;
}

int *remplire_mat(int N){
	int i,j;	
	int *T=allouer(N);
	for (i=0;i<N;++i)
		for(j=0;j<=i;++j){
				*(T+i*N+j)=combin(i,j);
		}
	return T;
}

void affiche_mat(int *M,int N){
	int i,j;	
	for (int p=N,i=0;i<N;++i,--p){
		for(j=0;j<p-1;++j)
			printf("  ");
		for(j=0;j<=i;++j){
			printf("  %d  ",*(M+i*N+j));
		}
		printf("\n");
	}
}


long long int combin(long long int  n , long long int p){
	if (p==0 || p==n)
		return 1;
	else return combin(n-1,p-1)+combin(n-1,p);
}

