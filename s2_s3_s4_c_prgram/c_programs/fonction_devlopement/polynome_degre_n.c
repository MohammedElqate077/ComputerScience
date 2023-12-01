#include<stdio.h>
#include<stdlib.h>

int main(){
	
	double x,a,p=0;
	int n;

	printf("enter x et n respictivement\n");
	scanf("%lf%d",&x,&n);

	while(n>0){
		
		printf("entre le coeficion numero %d : ",n);
		scanf("%lf",&a);

		p=(a+p)*x;
		n--;

	}

	printf("entre le coeficion numero 0 : ");
	scanf("%lf",&a);
	printf("P(x)=%.2lf\n",p+a);

	return 0;


}

