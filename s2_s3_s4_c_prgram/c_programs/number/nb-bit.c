#include<stdio.h>
#include<stdlib.h>

int main(){
	int n,bit=1;

	printf("enter un entier n\n");
	scanf("%d",&n);

	while(n/2>0){
		bit++;
		n/=2;
	}
	
	printf("nb de bits necessaires est %d\n",bit);

	return 0;
}
