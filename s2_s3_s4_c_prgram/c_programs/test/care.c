#include<stdio.h>
#include<stdlib.h>

double care(double n){
	if (n==0)
		return 0;
	else 
		
		return care(n-1)+(2*(n-1))+1;
}

int main(){
	double n;
	printf("entrer n : ");scanf("%lf",&n);
	if (n<0) {n=-n;}
	printf("n^2=%.2lf\n",care(n));
}






