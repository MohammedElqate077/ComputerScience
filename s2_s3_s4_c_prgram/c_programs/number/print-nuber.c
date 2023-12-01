#include<stdio.h>
#include<stdlib.h>

int number(int n){
	while (n>=0){
		printf("%d ",n);
		n--;
	}
	printf("\n");
}

int main(){
	int n;
	printf("n=");scanf("%d",&n);
	number(n);
}
