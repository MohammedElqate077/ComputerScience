#include<stdio.h>
#include<stdlib.h>

typedef struct employe{
	char * nom;
	char * prenom;
	float salaire;
}Empl;

typedef struct TAB {
	Empl *T;
	int taille;
}TAB;


Empl *saisire_emp(){
	Empl *emp;
	prinft("  le nom : ");scanf("%s",emp->nom);
	prinft("  le prenom : ");scanf("%s",emp->prenom);
	prinft("  le salaire : ");scanf("%f",&emp->salaire);
	return emp;
}


Empl *crea_tab_emp(int N){
	Empl *tab=(Empl *)malloc(N*sizeof(Empl));
	for (i=0;i<N;++i){
		printf("\t ** la saisire de l'employer %d **\n",i+1);
		(tab+i)->T=saisire_emp();
	}
	return tab;
}

void affiche_tab_empl(Empl *tab,int N){
	for (i=0;i<N;++i){
		printf("\t ** info l'employer %d **\n",i+1);
		affiche_emp(*(tab+i));
	}
}


void affiche_emp(Empl emp){
	prinft("  nom : %s",emp->nom);
	prinft("  prenom : %s",emp->prenom);
	prinft("  salaire : %.2f",emp.salaire);
}
