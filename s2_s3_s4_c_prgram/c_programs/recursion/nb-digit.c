#include<stdio.h>
#include<stdlib.h>

int getdigit(int n,int count){
	
	if(n==0){
		return count;
	}
	else{
		//count++;
		//printf("%d\n",n );
		return getdigit(n/10,++count);//not count++
	}
}

int main(){
	int n;
	int count=0;
	//do{
	printf("entrer a nombre positif n : ");scanf("%d",&n);
	//}while(n<0);
	printf("nb de chifre de %d est %d\n",n,getdigit(n,count));
}
