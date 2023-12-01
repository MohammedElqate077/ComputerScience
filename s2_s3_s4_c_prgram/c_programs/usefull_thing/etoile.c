#include<stdio.h>

int main(){
	int i,j,n;
	printf("dene n : ");scanf("%d",&n);
	int p=n;
	for(i=1;i<=n;i++){
		for(j=1;j<p;j++){
			printf(" ");
		}
		p--;
		for(j=1;j<=(2*i-1);j++){
			printf("*");
		}

		printf("\n");
	}
}
