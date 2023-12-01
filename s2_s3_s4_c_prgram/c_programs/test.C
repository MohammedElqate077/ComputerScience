#include<stdio.h>
#include<stdlib.h>
int main(void){

	int a = 25, b = 5, c = 10,d = 7;

	int n=2029;
	int some=0,m;
	while(n>0){
		m=n%10;
		some+=m;
		n/=10;
		if(n==0){
			printf("reselta %d \n",some);
			if (some>9)
				n=some;
				some=0;
		}
			
	}


	printf("a = 25  b = 5  c = 10  d = 7\n");
	printf("a  / d * d =%d\n",a  / d * d);
	printf(" a / d=%d\n",a / d);
	printf("a \% d  =%d\n",a % d);
	printf("a / d * d + a % d  =%d\n",a / d * d + a % d);
}
