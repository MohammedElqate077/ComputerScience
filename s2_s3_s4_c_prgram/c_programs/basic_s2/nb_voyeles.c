#include<stdio.h>
#include<stdlib.h>

int main (){
	
	char X;
	unsigned int nb_a=0,nb_e=0,nb_i=0,nb_o=0,nb_u=0;
	
	while((X=getchar())!=EOF){
		switch(X){
		
		case 'a': nb_a++ ;break;

		case 'e': nb_e++ ;break;

		case 'i': nb_i++ ;break;

		case 'o': nb_o++ ;break;

		case 'u': nb_u++ ;break;
		}
	}

	printf("nombre de a %d\n",nb_a);
	printf("nombre de e %d\n",nb_e);
	printf("nombre de i %d\n",nb_i);
	printf("nombre de o %d\n",nb_o);
	printf("nombre de u %d\n",nb_u);

	return 0;	

}