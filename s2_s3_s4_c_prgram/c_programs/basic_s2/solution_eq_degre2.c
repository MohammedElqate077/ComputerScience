#include<stdio.h>
#include<stdlib.h>
#include<math.h>

	
int main(){

	float a,b,c,delta;

	printf("enter les coeficion de l'eq a,b et c respictivment\n");
	scanf("%f%f%f",&a,&b,&c);
	delta=b*b-(4*a*c);

	if(delta==0)
		printf("la solution est %.2lf\n",(double)(-b)/(2*a)); 
	else if(delta>0) 
		printf("2 sloution x1=%.2lf x2=%.2lf\n",(double)(-b-sqrt(delta))/(2*a),(double)(-b+sqrt(delta))/(2*a));
	else 
		printf("l'eq n'a pas de solution\n");


	return 0;
}
