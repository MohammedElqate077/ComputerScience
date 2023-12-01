


#include<stdio.h>
#include<stdlib.h>

int *allouer(int N);
int *remplire_mat(int N);
void affiche_mat(int *M,int N);
long long int combin(long long int  n , long long int p);

int main (){
	int N;
	printf("entre dimention du matrice : ");scanf("%d",&N);
	int *T=allouer(N);
	T=remplire_mat(N);
	affiche_mat(T,N);


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
	int *T=(int *)calloc(N*N,sizeof(int));
	for (i=0;i<N;++i)
		for(j=0;j<=i;++j){
			if(j==0 || i==j)
				*(T+i*N+j)=1;
			else
				*(T+i*N+j)=*(T+(i-1)*N+j) + *(T+(i-1)*N+j-1);
		}
	return T;
}

void affiche_mat(int *M,int N){
	int i,j;	
	for (i=0;i<N;++i){
		for(j=0;j<=i;++j){
			printf(" %d ",*(M+i*N+j));
		}
		printf("\n");
	}
}


long long int combin(long long int  n , long long int p){
	if (p==0 || p==n)
		return 1;
	else return combin(n-1,p-1)+combin(n-1,p);
}

