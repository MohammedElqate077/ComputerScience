#include<stdio.h>
#include<stdlib.h>

int number(int n){
	if(n==0){
		printf("%d\n",n );
		return 0;
	}
	else 
		printf("%d ",n);
		return number(n-1);
}

int main(){
	int n;
	printf("n=");scanf("%d",&n);
	number(n);
}
