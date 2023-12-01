
#include<stdio.h>
#include<stdlib.h>

int fibi(int n){
	int i=2,f=0,f0=1,f1=1;
	
	while(i<=n){
		f=f0+f1;
		f0=f1;
		f1=f;
		i++;
	}
	return f;
}
int main(){
	int n;
	int f;
	printf(" donner un entier :");
	scanf("%d",&n);
	f=fibi(n);
	printf("le %d eme terme est : %d\n",n,f);
	
}
