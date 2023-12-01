#include<stdio.h>
#include<stdlib.h>

typedef struct Le_nombre_comlexe {
	float reel;
	float imagi;
}NbCp;

void lire_complexe1(NbCp *C);
NbCp lire_complexe2(NbCp C);
void affiche_complexe1(NbCp C);
void affiche_complexe2(NbCp *C);

int main (){
	NbCp complexe;

	printf("using lire comlexe 1\n"); 
	lire_complexe1(&complexe);
	affiche_complexe1(complexe);

	printf("using lire comlexe 2\n");
	complexe=lire_complexe2(complexe);
	affiche_complexe2(&complexe);
}

void lire_complexe1(NbCp *C){
	printf("entre le coeffecion reel\n");scanf("%f",&C->reel);
	printf("entre le coeffecion imaginaire\n");scanf("%f",&C->imagi);
}

NbCp lire_complexe2(NbCp C){
	printf("entre le coeffecion reel\n");scanf("%f",&C.reel);
	printf("entre le coeffecion imaginaire\n");scanf("%f",&C.imagi);
	return C;
}

void affiche_complexe1(NbCp C){
	printf(" %5.2f + %5.2fi\n",C.reel,C.imagi);
}

void affiche_complexe2(NbCp *C){
	printf(" %5.2f + %5.2fi\n",C->reel,C->imagi);
}