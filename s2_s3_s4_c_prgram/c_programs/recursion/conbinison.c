#include<stdio.h>
#include<stdlib.h>

long long int combin(long long int  n,long long int p);

int main (){
	long long int n,p;
	printf("entrer n et p (respectivement)\n");scanf("%lld%lld",&n,&p);
	long long int  a=combin(n,p);
	printf("%lldC%lld = %lld\n",p,n,a);
}

long long int combin(long long int  n , long long int p)
{
	if (p==0 || p==n)
		return 1;
	else return combin(n-1,p-1)+combin(n-1,p);
}

