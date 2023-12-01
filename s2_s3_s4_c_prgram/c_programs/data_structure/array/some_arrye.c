#include<stdio.h>

// **** avec pointeur : en commentaire fin du programme***

int main(){
	int dim,i;
	int s=0;

	printf("\nenter le dimention du tableau (max=50) : ");
	scanf("%d",&dim);

	int T[dim-1];
	for(i=0;i<dim;i++){
		
		printf("entrer valeurs num %d : ",i);
		scanf("%d",&T[i]);

		s+=T[i];
		
	}

	printf("T[%d]={",dim);

	for(i=0;i<dim;i++){

		printf(" %d ",T[i]);
		
	}
	
	printf("}\nsomes des elemnet de tableau : %d\n",s);
	
	return 0;
}

/*	// **** avec pointeur
#include<stdio.h>

int main(){
	int dim,*p,s=0;

	printf("\nenter le dimention du tableau (max=50) : ");
	scanf("%d",&dim);

	int T[dim];
	for(p=T;p<T+dim;p++){
		
		printf("entrer valeurs num %ld : ",p-T);
		scanf("%d",p);

		s+=*p;
		
	}

	printf("T[%d]={",dim);

	for(p=T;p<T+dim;p++){

		printf(" %d ",*p);
		
	}
	
	printf("}\nsomes des elemnet de tableau %d\n\n",s);
	
	return 0;
}
*/

/*

#include<stdio.h>

int main(){
	int dim,;
	int s=0;

	printf("enter le dimention du tableau (max=50) : ");
	scanf("%d",&dim);

	int T[dim];
	while(dim>0){
		
		printf("entrer valeurs num %d\n",dim--);
		scanf("%d",&T[dim]);

		s+=T[dim];
		//dim-=1;
	}
	

	// probleme perde de dimention dimention

	while(dim=0){
		printf("T[%d]={%d}",dim,T[dim]);
		dim+=1;
	}
	
	printf("somes des elemnet de tableau %d\n",s);
	getchar();

	return 0;
}

*/