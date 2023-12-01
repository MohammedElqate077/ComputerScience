#include<stdio.h>
#include<stdlib.h>

int main(){
	float x;
	printf("donner la valeure de la reel x\n");
	scanf("%f",&x);
	if(x<=0){
		x=-x;
	}
	printf("la valeure absolu de x est %.2f \n",x);
}
