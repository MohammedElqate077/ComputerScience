#include<stdio.h>
#include<stdlib.h>
int main(){
	int n,racin;
	printf("doner le nombre entier n\n");
	scanf("%d",&n);
	racin=1;
	while(racin*racin<=n)
	{
		racin=racin+1;
	}
	printf("la racin entier %d et %d\n",n,racin-1);
	
}
