#include<stdio.h>
#include<stdlib.h>

int some_rec(int n,int s){
	if(n==0)
		return s;
	else 
		return some_rec(n-1,s+n);
}

int main(){
	int n,s=0;
	printf("entrer n : ");scanf("%d",&n);
	printf("la some est %d\n",some_rec(n,s));
}

/* 
int some_rec(int n){
	if(n==0)
		return 0;
	else 
		return n+some_rec(n-1);
}
*/
