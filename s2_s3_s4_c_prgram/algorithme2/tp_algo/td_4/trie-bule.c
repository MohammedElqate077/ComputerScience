#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void echange(int T[],int x,int y){
	int temp=T[x];
	T[x]=T[y];
	T[y]=temp;
}
/*
void echange(int *x,int *y){
	int temp=*x;
	*x=*y;
	*y=temp;
}
*/
void tri_bule(int T[],int n){
	bool repass;
	int j;
	int i=n-1;
	do{
		repass=false;
		j=0;
		while(j<=i-1){
			if(T[j]>T[j+1]){
				echange(T,j,j+1);// echange(&T[j],&T[j+1]);
				repass=true;
			}
			j++;
		}
		i--;
	}while(repass || i>=1);

}
//	}while(repass==1 || i!=0);
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
	
	tri_bule(T,n);
	
	affiche_tableau(T,n);
	return 0;
}
/*
void echange(int *x,int *y){
	int temp=*x;
	*x=*y;
	*y=temp;
}

void tri_bule(int T[],int n){
	bool repass;
	int j;
	do{
		repass=false;
		for(j=0;j<n-1;j++){
			if(T[j]>T[j+1]){
				echange(&T[j],&T[j+1]);
				repass=true;
			}
		}
	}while(repass);
}


void tri_bule(int T[],int n){
	bool repass;
	int j;
	int i=n-1;
	do{
		repass=false;
		j=i-1;
		while(j>=0){
			if(T[j]>T[j+1]){
				echange(&T[j],&T[j+1]);
				repass=true;
			}
			j--;
		}
		i--;
	}while(repass==1 || i!=0);
}
*/
