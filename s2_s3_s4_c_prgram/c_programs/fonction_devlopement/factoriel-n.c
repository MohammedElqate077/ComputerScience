#include<stdio.h>
#include<stdlib.h>
int main(){
	int n,i;
	long double f=1;
	printf("entere un entier positif n\n");
	scanf("%d",&n);
	while(n<0){
		printf("entere un entier positif n=>0\n");
		scanf("%f",&n);	
	}
	if(n==0)
		printf("%d!=1\n",n);
	else{
		
		for(i=1;i<=n;i++){
			f*=i;
		}
		printf("%d!=%Lf\n",n,f);
	}
	return 0;

}






/*
#include<stdio.h>

void main(){
	
	int i,n;
	long double f=1;
	
	printf("entrer n\n");
	scanf("%d",&n);
	
	while(0<n){
		f*=n;
		n--;
	}
	//
	//for(i=1;i<=n;i++){
	//	f*=i;
	//}
	//
	printf("resultat est %.0Lf\n",f);
	
	

}

*/



