#include<stdio.h>
int main()
{
	float a,b,c,d,max,min; 
	printf("donne les valeures des 4 nombres\n");
	scanf("%f %f %f %f",&a,&b,&c,&d);
	if (a<b) 
	{	max=b;
		min=a;
	}
	else {

		max=a;
		min=b;
	}
	if (max<c){
		max=c;
	}
	else{
		if (min>c){
			min=c;
		}

	}
	if (max<d){
		max=d;
	}
	else{
		if (min>d){
			min=d;
		}

	}
	printf("le max est %.2f et le min %.2f\n",max,min);
	

}
