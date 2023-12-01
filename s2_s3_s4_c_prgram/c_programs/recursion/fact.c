#include<stdio.h>
#include<stdlib.h>

double fact(int n);
int main(){
	int n;
//if (n<0) n=-n;
	printf("entrer n = ");scanf("%d",&n);
	printf("%.0lf\n",fact(n));
	getchar();	

}

double fact(int n){
	if(n==0)
		return 1;
	else return n*fact(n-1);
}


/*terminale
double fact(int n,int v){
	//int i;
	if(n==0)
		return v;
	else return fact(n-1,n*v);
}
*/
