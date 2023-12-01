#include<stdio.h>
#include<stdlib.h>

void trie_bulle(int T[],int n);
void echange(int *x,int *y);
void affich_tableau(int T[], int n);
int main(){
	
	int n,i,T[100];
	printf("entrer n : ");scanf("%d",&n);
	for (i=0;i<n;i++){
		printf("T[%d]=",i);scanf("%d",&T[i]);
	}

	printf("tableau donne\n");
	affich_tableau(T,n);

	trie_bulle(T,n);

	printf("tableau trier\n ");

	affich_tableau(T,i);


	return 0;

}

void trie_bulle(int T[],int n){
	int repass;
	int j;
	do{
		repass=0;
		for(j=0;j<n-1;j++){
			if(T[j]>T[j+1]){
				echange(&T[j],&T[j+1]);
				repass=1;
			}
		}
		n--;
	}while(repass);

}
void echange(int *x,int *y){
	int temp=*x;
	*x=*y;
	*y=temp;
}

void affich_tableau(int T[], int n) {

  for(int i=0;i<n;i++) {
    printf("%d  ",T[i]);
  }
  printf("\n");
}

