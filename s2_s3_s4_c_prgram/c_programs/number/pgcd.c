#include<stdio.h>
#include<stdlib.h>

void main(){

	int a,b,r;

	printf("a=");
	scanf("%d",&a);
	printf("b=");
	scanf("%d",&b);

	if(b>a){
		r=a;
		a=b;
		b=r;
	}

	while (a%b != 0){
		r=a%b;
		a=b;
		b=r;
	}
	printf("le pgcd est %d\n",b);
	
	

}
