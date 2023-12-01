#include<stdio.h>
#include<stdlib.h>
void echange(int T[],int i,int posmin){
		int val=T[i];
		T[i]=T[posmin];
		T[posmin]=val;
	
}

int getmin(int T[],int i,int n){
	int j,pos=i;

	for(j=i+1;j<n;j++){
		if(T[pos]>T[j]){
			pos=j;
		}
	}
	return pos;
}

void tri_select(int T[],int n){
	int i,posmin;

	for(i=0;i<n-1;i++){
		posmin=getmin(T,i,n);
		echange(T,i,posmin);
	}
}

void affich_tableau(int T[], int n) {

  for(int i=0;i<n;i++) {
    printf("%d  ",T[i]);
  }
  printf("\n");
}

int main(){

	int n,i,T[100];

	printf("entrer n : ");scanf("%d",&n);

	for (i=0;i<n;i++){
		printf("T[%d]=",i);scanf("%d",&T[i]);
	}

	printf("tableau donne\n");
	affich_tableau(T,n);

	tri_select(T,n);

	printf("tableau trier\n ");

	affich_tableau(T,n);


	return 0;
}

/* 

void trie_croi(int *T,int nb){
	int v;
	for(int i=0;i<nb;i++){
		for(int j=i+1;j<nb;j++){
			if(T[i]>T[j]){			// bad complixite {a chaque condition verfier echange}
				v=T[i];
				T[i]=T[j];
				T[j]=v;
			}
		}
	}
}
*/
