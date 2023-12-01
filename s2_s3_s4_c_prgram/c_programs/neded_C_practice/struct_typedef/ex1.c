#include<stdio.h>
#include<math.h>
#include<stdlib.h>

typedef struct {
	float reel;
	float imagi;
}nb_comp;

void saisire_complexe(nb_comp *C){
	printf("entre le coeffecion reel : ");scanf("%f",&C->reel);
	printf("entre le coeffecion imaginaire : ");scanf("%f",&C->imagi);
}

void affiche_complexe(nb_comp C){
	printf(" Z = %5.2f + i%5.2f\n",C.reel,C.imagi);
}

nb_comp conjug(nb_comp C){
	nb_comp D;

	D.reel=C.reel;
	D.imagi=-C.imagi;

	return D;
}

float module_complex(nb_comp C){
	return sqrt(C.reel*C.reel+C.imagi*C.imagi);
}

int main (){
	nb_comp complexe;

	printf("saisire le nb complexe \n\n"); 
	saisire_complexe(&complexe);

	printf("affiche le nb complexe \n\n"); 
	affiche_complexe(complexe);

	printf("affiche le conjuge le nb complexe \n\n"); 
	nb_comp C=conjug(complexe);
	printf("Z(bar) = %.2f - i%.2f \n",C.reel,-C.imagi);

	printf("affiche le modue de nb complexe \n\n"); 
	printf("|Z| = %6.3f\n",module_complex(complexe));

}
