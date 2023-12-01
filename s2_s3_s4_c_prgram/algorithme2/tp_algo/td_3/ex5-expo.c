
#include<stdio.h>
#include<stdlib.h>

int fact(int n){
	if(n==0||n==1) return 1;
	return n*fact(n-1);
}
int puiss(float x,int n){
	if(n==0) return 1;
	else x*puiss(x,n-1);
}
float expon(float x, int n){
	if(n==0) return 1;
	else return expon(x,n-1)+(float)puiss(x,n)/fact(n);
}
int main(){
	int n;
	float x;
	float e;
	printf(" donner un entier :");
	scanf("%d",&n);
	printf("donner un  reel :");
	scanf("%f",&x);
	e=expon(x,n);
	printf("le DL a l ordre %d est : %f",n,e);
	
}

/*	version eteratif
int main(){
	int n;
	double fact=1,pow=1,s=1,x;

	printf("x = ");scanf("%lf",&x);
	printf("n = ");scanf("%d",&n);

	for(int k=1 ;k<=n;k++){
		pow*=x;
		fact*=k;
		s+=(pow/fact);
	}
	printf("e^%.2lf a l'aurdre %d est %7lf\n",x,n,s);
}
*/
