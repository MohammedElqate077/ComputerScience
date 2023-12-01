


#include<stdio.h>
#include<stdlib.h>

int **allouer(int N);
int **remplire_mat(int N);
void affiche_mat(int **M,int N);
long long int combin(long long int  n , long long int p);

int main (){
	int N;
	printf("entre dimention du matrice : ");scanf("%d",&N);
	int **T=allouer(N);
	T=remplire_mat(N);
	affiche_mat(T,N);

	return 0;
}

int **allouer(int N){
	int **T=(int **)malloc(N*sizeof(int*));
	for(int i=0;i<N;++i){
		T[i]=(int *)calloc(N,sizeof(int));
		if (T[i]==NULL){ 
			printf("memoire non allouer");
			exit(0);
		}
	}
	return T;
}

int **remplire_mat(int N){
	int i,j;	
	int **M=(int **)malloc(N*sizeof(int*));
	for(i=0;i<N;++i){
		M[i]=(int *)calloc(N,sizeof(int));
	}
	for (i=0;i<N;++i)
		for(j=0;j<=i;++j){		
			if(j==0 || i==j)
				*(M[i]+j)=1;
			else
				
				//*(M[i]+j) = *(M[i-1]+j) + *(M[i-1]+j-1) ;
				M[i][j]=M[i-1][j-1]+M[i-1][j];
			
		}
	return M;
}

void affiche_mat(int **M,int N){
	int i,j;	
	for (i=0;i<N;++i){
		for(j=0;j<=i;++j){
			printf(" %d ",*(M[i]+j));
		}
		printf("\n");
	}
}


long long int combin(long long int  n , long long int p){
	if (p==0 || p==n)
		return 1;
	else return combin(n-1,p-1)+combin(n-1,p);
}

