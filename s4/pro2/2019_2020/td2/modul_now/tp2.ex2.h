#include<stdio.h>
#include<stdlib.h>

typedef struct Employe{
	char nom[20];
	char prenom[20];
	float salaire;
}Empl;





Empl saisire_emp();
void *crea_tab_emp(int N);
void *saisire_tab_emp(int N);
void affiche_tab_empl(Empl *tab,int N);
void affiche_emp(Empl emp);

void *crea_tab_emp(int N){
	Empl *tab=(Empl *)malloc(N*sizeof(Empl));
	
	if(tab==NULL){
		printf("allocation faild");
		exit(0);
	}
	return tab;
}

Empl saisire_emp(){
	Empl emp;
	printf("  le nom : ");scanf("%s",emp.nom);
	printf("  le prenom : ");scanf("%s",emp.prenom);
	printf("  le salaire : ");scanf("%f",&emp.salaire);
	printf("\n");
	return emp;
}

void *saisire_tab_emp(int N){
	Empl *tabl=(Empl *)malloc(N*sizeof(Empl));
	if(tabl==NULL){
		printf("allocation de saisire faild\n");
		exit(0);
	}
	for (int i=0;i<N;i++){
		printf("\t ** la saisire de l'employer %d **\n\n",i+1);
		*(tabl+i)=saisire_emp();
	}
	return tabl;
}

void affiche_tab_empl(Empl *tab,int N){
	for (int i=0;i<N;++i){
		printf("\t ** info l'employer %d **\n",i+1);
		affiche_emp(*(tab+i));
	}
}


void affiche_emp(Empl emp){
	printf("  nom : %s\n",emp.nom);
	printf("  prenom : %s\n",emp.prenom);
	printf("  salaire : %.2f\n",emp.salaire);
}
