#include<stdio.h>
#include<stdlib.h>

#define degmax 10

typedef struct {
	float X[degmax];
	float coeff[degmax];
	int deg;
}Poly;

void LirePolynome(Poly *P) {
	printf("\n\n Enter le degre du polnome (max %d) : ",degmax);
	scanf("%d",&P->deg);
	for(int i=0;i<P->deg;i++)
	{
		printf("   Enter X %d : ",i);
		scanf("%f",&P->X[i]);      

		printf("   Enter le coiefficient %d : ",i);
		scanf("%g",&P->coeff[i]);

	}
 }

void affiche_poynome(Poly *P){
	int i=P->deg-1;
	printf("\n\n P(X) = ");
	while(i>0){
		printf(" %.f(%.f^%d) +",P->coeff[i],P->X[i],i);
		i--;
	}
	printf(" %.f(%.f^%d)\n",P->coeff[i],P->X[i],i);
}

int main(){
	Poly P;
	printf("\t\t ** info poly \n");
	LirePolynome(&P);
	printf("\t\t ** affichage poly \n");
	affiche_poynome(&P);

}
