#include<stdio.h>
#include<stdlib.h>

int get_sum_digit(int n,int sum){
	
	if(n==0){
		return sum;
	}
	else{
	//	sum+=(n%10);
	//	printf("%d\n",n );
		return get_sum_digit(n/10,sum+=(n%10));
	}
}

int main(){
	int n,sum=0;
	do{
		printf("entrer a nombre positif n : ");scanf("%d",&n);
	}while(n<0);
	printf("some de chifre de %d est %d\n",n,get_sum_digit(n,sum));
}

/*
int get_sum_digit(int n,int sum){
	
	if(n==0){
		return sum;
	}
	else{
		sum+=(n%10);
		//printf("%d\n",n );
		return get_sum_digit(n/10,sum);
	}
}
*/