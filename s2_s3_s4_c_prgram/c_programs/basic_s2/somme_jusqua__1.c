#include<stdio.h>
#include<stdlib.h>

int main(){
	int s=0,n=0,nb=-1;


	do{

		s+=n;
		nb++;
		printf("donner n\n");
		scanf("%d",&n);
		
	}while(n!=-1);

	printf("le moyen de %d entier est %.2f\n",nb,(float)s/(nb));

	return 0;
}

/*  or the code below
int main(){
	int s=0,n=0,nb=0;
	do{
		s+=n;
		printf("donner n\n");
		scanf("%d",&n);
		nb++;
	}while(n!=-1);
	printf("le moyen de %d entier est %.2f\n",nb-1,(float)s/(nb-1));

}
*/	
