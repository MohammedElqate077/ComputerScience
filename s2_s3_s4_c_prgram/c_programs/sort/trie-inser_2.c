#include<stdio.h>
#include<stdlib.h>

void tri_insert(int T[],int n){
	
	int i,j,key;
	for(i=1;i<n;i++){
		key=T[i];
		j=i-1;
		while(j>=0 && T[j]>key){
			T[j+1]=T[j];
			j--;
		}
		T[j+1]=key;
	}
}

void affiche_tableau(int T[],int n){
	
	for(int i=0;i<n;i++){
		printf("%d ",T[i]);
	}
	printf("\n");
}

int main(){
	int n,i,T[100];
	printf("donner n : ");scanf("%d",&n);

	for (i=0;i<n;i++){
		printf("T[%d]=",i);
		scanf("%d",&T[i]);
	}

	tri_insert(T,n);

	affiche_tableau(T,n);
	return 0;
}

/*

void tri_insert(int T[],int n){
	
	int i,j,key;

	for(i=1;i<n;i++){
		key=T[i];
		for(j=i;j>0 && T[j-1]>key;j--){
			T[j]=T[j-1];
		}
		T[j]=key;
	}
}
*/
