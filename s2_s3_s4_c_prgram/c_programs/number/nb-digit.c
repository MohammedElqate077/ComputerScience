#include<stdio.h>
#include<stdlib.h>

int getdigit(int n,int count){
	
	while (n>0){
		n/=10;
		count++;
	}
	return count;
}

int main(){
	int n;
	int count=0;
	//do{
	printf("entrer a nombre positif n : ");scanf("%d",&n);
	//}while(n<0);
	printf("nb de chifre de %d est %d\n",n,getdigit(n,count));
}
