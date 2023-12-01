#include<stio.h>
#include<stdlib.h>
void main (void){
	int *T;
	int n,i;
	printf("entrer dimention du tableau:");scanf("%d",&n);
	T=(int *)malloc(n*sizeof(int));	
	if(T==NULL)
		printf("memoire nom allouer\n");
		exit(0);
	else 			
		printf("memoire allouer avec succes\n");
	for (i=0;i<n;i++)
		printf("T[%d]=",i+1);scanf("%d",T+i);
	
}
