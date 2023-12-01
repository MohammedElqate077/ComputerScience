#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int palindrome(char R[],int i,int n);
void affiche(int a,char R[]);

int main (){
	char R[1000];
	int a,i=0;

	printf("entrer le mot : ");scanf("%s",R);
	a=palindrome(R,i,strlen(R)-1);
	affiche(a,R);
}

int palindrome(char R[],int i,int n){
	
	if(R[i]!=R[n]){
		return 0;
	}
	if (i>n){
			return 1;
	}
	return palindrome(R,++i,--n);
}

void affiche(int a,char R[]){
	if(a==1)
		printf("%s est palindrome\n",R);
	else
		printf("%s n'est pas palindrome\n",R);
}

//	avec version eteratif	//
/*
int palindrome(char R[],int n){
	int i=0;
	while(i<n){			//	or	while(i<(n-i))
		if(R[i]!=R[n]){	//	or	if(R[i]!=R[n-i])
			return 0;
		}
		i++;			
		n--;			// whitout this line
	}
	return 1;
}
*/
