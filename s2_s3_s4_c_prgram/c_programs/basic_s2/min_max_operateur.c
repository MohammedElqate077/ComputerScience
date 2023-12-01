#include<stdio.h>
int main(){
	int a,b,c,res;
	printf("entrer 2 entier pour le min\n");
	scanf("%d%d%",&a,&b);
	
	/*
	res=a<b?a:b;
	printf("le min est %d\n",res);
	*/
	
	if (a<b)
		printf("le min est %d\n",a);
	
	else
		printf("le min est %d\n",b);
	
	printf("enter 3 entier pour le max\n");
	scanf("%d%d%d",&a,&b,&c);
	
	if(a>b)
		res=a;
	else 
		res=b;
	if(res<c)
		res=c;
	/*
	res=a>b?a:b;
	res=res>c?res:c;
	*/
	printf("le max est %d\n",res);
}
