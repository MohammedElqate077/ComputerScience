#include<stdio.h>
#include<stdlib.h>

int some_shifre(int a);
int recherch(int v,int T[],int k);
void affiche(int T[],int p,int i);

int main(){
	int p=0,i,U[10000];

	do{
	printf("entre u(0)>1  : ");
	scanf("%d",&U[0]);
	}while(U[0]<=1);

	i=0;
	do{
		i++;
		U[i]=some_shifre(U[i-1]);
		p=recherch(U[i],U,i);
	}while((p == -1));
	//}while((U[i-1] != U[i-2]) && (p == -1)); 
	/* comparison of U[i-1] and U[i] is not nessesry becose all ways p=-1 verfied if a nb repeted in the arrays */

	affiche(U,p,i);
}

int some_shifre(int a){
	int s=0;

	while(a!=0){
		s+=(a%10)*(a%10);
		a/=10;}
	return s;
}

int recherch(int v,int T[],int k){
	int i;
	for(i=0;i<k;i++)
		if (T[i]==v)
			return i;
	//	else return some_shifre(v);	
	return (-1);
}

void affiche(int T[],int p,int b){
	int j;
	
		if(T[b]!=T[b-1]){
			printf("suite periodique ces terme  periodique sont :\n{");
			for (j=p;j<b;j++)
				printf(" %d ",T[j]);
		}
		else{
			printf("suite constant ces terme sont :\n{");
			for (j=0;j<b;j++){
				printf(" %d ",T[j]);
			}
		}
			
	printf("}\n");	
}

/*
#include<stdio.h>
#include<stdlib.h>

int chifres(int n);
int recherch_x(int x,int T[],int n);
int affiche(int T[],int p,int i);

int main(){
	int p,i,T[100];

	do{
	printf("entre u(0)>1  : ");
	scanf("%d",&T[0]);
	}while(T[0]<=1);
	i=1;
	do{
		T[i]=chifres(T[i-1]);
		p=recherch_x(T[i],T,i);
		i++;
	}while((T[i-1] != T[i-2]) && (p == -1));
	affiche(T,p,i);
}

int chifres(int n){
	int s=0;

	while(n!=0){
		s+=(n%10)*(n%10);
		n/=10;}
	return s;
}

int recherch_x(int x,int T[],int n){
	int i;
	for(i=0;i<n;i++)
		if (T[i]==x)
			return i;
	return -1;
}

int affiche(int T[],int p,int i){
	int j;

		if(T[i-1]==T[i-2]){
			printf("constant :\n{");
			for (j=0;j<i-1;j++){
				printf(" %d ",T[j]);
			}
		}
		else{
			printf("periodique :\n{");
			for (j=p;j<i-2;j++)
				printf(" %d ",T[j]);
		}
		printf("}\n");	
}
*/





/*

#include<stdio.h>
#include<stdlib.h>

int some_shifre(int a);
int recherch(int v,int T[],int k);
void affiche(int T[],int p,int i);

int main(){
	int p=0,i,U[10000];

	do{
	printf("entre u(0)>1  : ");
	scanf("%d",&U[0]);
	}while(U[0]<=1);

	i=1;
	do{
		U[i]=some_shifre(U[i-1]);
		p=recherch(U[i],U,i);
		i++;
	}while((p == -1));
	//}while((U[i-1] != U[i-2]) && (p == -1));

	affiche(U,p,i);
}

int some_shifre(int a){
	int s=0;

	while(a!=0){
		s+=(a%10)*(a%10);
		a/=10;}
	return s;
}

int recherch(int v,int T[],int k){
	int i;
	for(i=0;i<k;i++)
		if (T[i]==v)
			return i;
	//	else return some_shifre(v);	
	return (-1);
}

void affiche(int T[],int p,int b){
	int j;
	

	
		if(T[b-1]!=T[b-2]){
			printf("suite periodique ces terme  periodique sont :\n{");
			for (j=p;j<b-1;j++)
				printf(" %d ",T[j]);
		}
		else{
			printf("suite constant ces terme sont :\n{");
			for (j=0;j<b-1;j++){
				printf(" %d ",T[j]);
			}
		}
		
		
	printf("}\n");	
}


*/
