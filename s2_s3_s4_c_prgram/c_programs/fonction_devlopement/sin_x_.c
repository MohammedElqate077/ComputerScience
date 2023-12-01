#include<stdio.h>
#include<stdlib.h>

int main (){
	double x,epsi,p,result,preci;
	int n,fact,s;

	printf("donne x : ");scanf("%lf",&x);
	printf("donne precision : ");scanf("%lf",&preci);

	//x=;
	//preci=;

	result=x;
	fact=3*2*1;
	n=3;
	p=x*x*x;
	s=-1;

	epsi=p/fact;

	while(epsi>preci){
		result+=s*epsi;
		n+=2;
		fact*=n*(n-1);
		p*=x*x;
		s*=-1;
		epsi=p/fact;
	}
	printf("le resulta est : %lf \n",result );

}

/*
#include <stdio.h>
unsigned long factorial(unsigned short int);
float power(float, unsigned short int);

int main() {
	unsigned short n, i = 0;
	float x, sum = 0;

	printf("n: ");
	scanf("%hu", &n);

	printf("x: ");
	scanf("%f", &x);

	while(i < n) {
		if(i%2 == 0)
			sum += power(x,2*i+1)/(float) factorial(2*i+1);
		else
			sum -= power(x,2*i+1)/(float) factorial(2*i+1);
		i++;
	}

	printf("Sum upto %hd terms = %f", n, sum);

	return 0;
}

float power(float x, unsigned short n) {
	float pow = 1;

	while(n > 0) {
		pow *= x;
		--n;
	}

	return pow;
}

unsigned long factorial(unsigned short n) {
	unsigned long f;

	if(n == 0 || n == 1)
		return 1;
	else
		f = n * factorial(n-1);

	return f;
}
*/

/*#include <stdio.h>
#include <math.h>

int fac(int x)
{
	int i,fac=1;
	for(i=1;i<=x;i++)
		fac=fac*i;
	return fac;
}

int main()
{
	float x,Q,sum=0;
	int i,j,limit;

	printf("Enter the value of x of sinx series: ");
	scanf("%f",&x);

	printf("Enter the limit upto which you want to expand the series: ");
	scanf("%d",&limit);

	Q=x;
	//x = x*(3.1415/180);

	for(i=1,j=1;i<=limit;i++,j=j+2)
	{
		if(i%2!=0)
		{
			sum=sum+pow(x,j)/fac(j);
		}
		else
			sum=sum-pow(x,j)/fac(j);
	}

	printf("Sin(%0.1f): %f",Q,sum);
	return 0;
}

*/