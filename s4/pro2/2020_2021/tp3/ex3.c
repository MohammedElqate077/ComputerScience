/*
 *MOHAMMED 
 *2021
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxnote 4

typedef struct {
	char nom[15];
	char prenon[15];
	char CNE[10];
	char filier[3];
	float notes[maxnote];
}Etudiant;

float moyenne_notes(Etudiant etud);

void lire_notes(float *notes){
	int i=0;
	while (i<maxnote ){
		printf("		note %d : ",i+1);scanf("%f",notes+i);
		while(notes[i]<0 || notes[i]>20){
			printf("		note imposible ,resairire la note %d : ",i+1);scanf("%f",notes+i);
		}
		i++;
	}
//	return note_valid;
}

void lire_Etudiant(Etudiant *etud,int n){



	for(int i=0;i<n;i++){
		printf("\n\n\t\t **** INFO Etudiant %d ****",i+1);
		printf("\n	nom : ");fflush(stdin);scanf("%s",etud[i].nom);
		printf("	prenon : ");fflush(stdin);scanf("%s",etud[i].prenon);
		printf("	CNE : ");fflush(stdin);scanf("%s",etud[i].CNE); 
		printf("	filier : "); scanf("%s",etud[i].filier);
		lire_notes(etud[i].notes);
	}
}


void affiche_Etudiant(Etudiant *etud,int n){
	//int i=0;
	for(int i=0;i<n;i++){
	
		printf("\n\n\t\t **** affichage de la Etudiant %d ****\n\n",i+1);
		printf("	nom : %s \n",etud[i].nom); 
		printf("	prenon : %s \n",etud[i].prenon); 
		printf("	filier : %s\n",etud[i].filier); 
		printf("	CNE : %s\n",etud[i].CNE); 
		printf("	le moyen : %.2f\n",moyenne_notes(etud[i]));
		printf("	affiche notes ");
		for(int j=0;j<maxnote;j++){
			printf("		note %d : %.2f\n",j+1,etud[i].notes[j]);
		}
	}
}

float moyenne_notes(Etudiant etud){
		int i=0;
		float some=0;
		while( i < maxnote){
			some+=etud.notes[i];
			i++;
		}
		return some/maxnote;
}

Etudiant *list_rat(Etudiant *etud,int n){
	Etudiant *etud_rat=(Etudiant*)malloc(n*sizeof(Etudiant));
	int i,j;
	for(i=j=0;i<n;i++){
			if (moyenne_notes(etud[i])<10){
				printf("	CNE etud %d : %s",j+1,etud[i].CNE);
				etud_rat[j]=etud[i];
				j++;
			}

	}
	etud_rat=(Etudiant *)realloc(etud_rat,j*sizeof(Etudiant));
	return	etud_rat; 

}

void search_etud(Etudiant *etud,int n){
	char CNE_S[10];
	printf("\n enter CNE rechearche :");scanf("%s",CNE_S);
	int i=0;
	while(i<n){
		if(strcmp(etud[i].CNE,CNE_S)==0) {
			printf("etud exit dans la pos %d \n",i);return;
		}
		i++;
	}
	printf("etudiant ne existe pas \n");return;
}

int main(){

	int n;
	Etudiant *etud;

	printf("\n Combien voulez vous saisir d'etudiants <1000 :  "); scanf("%d",&n);
	
	etud=(Etudiant*)malloc(n*sizeof(Etudiant));

	lire_Etudiant(etud,n);

	affiche_Etudiant(etud,n);

	printf("\n 			liste rat\n");
	Etudiant *etud_rat=list_rat(etud,n);

	printf("\n 			search rat\n");
	search_etud(etud,n);

	return 0;
}
