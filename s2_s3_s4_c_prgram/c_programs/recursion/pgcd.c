#include<stdio.h>
#include<stdlib.h>

int pgcd(int a,int b){		
	if((a%b)==0){
		return b;
	} 	
	else{
		
		return pgcd(b,a%b);
	}
}

int main(){
	int a,b;
	printf("entrer a et b respicti\n");scanf("%d%d",&a,&b);
	printf("pgcd=%d\n",pgcd(a,b));
	// il sufit que a>b ou faire une permutation
}
