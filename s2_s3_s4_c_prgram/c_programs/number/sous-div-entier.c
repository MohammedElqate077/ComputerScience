#include<stdio.h>
#include<stdlib.h>

int main (){
	int a,b,res,div=0;

	printf("entrer le numerateure\n");
	scanf("%d",&a);
	printf("enter le denominateur\n");
	scanf("%d",&b);

	res=a;

	while(res>=div){
		res=res-b;
		div++;
	}
	
	printf("%d/%d=%d*%d+%d\n",a,b,div,b,res);

	return 0;
}
