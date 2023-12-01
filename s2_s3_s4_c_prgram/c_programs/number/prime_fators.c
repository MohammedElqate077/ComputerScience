#include<stdio.h>
#include<stdlib.h>

long long int  factor_rec(long long int n,int i);

void main (){
	long long int n;
	printf("donne n=");scanf("%lld",&n);
	if (n==0) 
		printf("all numbers of IR are factors of 0");
	else 
		printf("1 ");
		factor_rec(n,2);
	printf("\n");
}

long long int factor_rec(long long int n,int i){
	if (i>n)
		return 0;
	else {
		if (n%i==0){
			printf("%d ",i);
			//long long int a=n/i;
			return factor_rec(n/i,2);
		}
		else 
			return factor_rec(n,++i);	
	}
}

