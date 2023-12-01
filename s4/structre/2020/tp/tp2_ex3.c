#include<stdio.h>
#include<stdlib.h>

typedef struct Etude{
	char nom[15];
	char prenom[15];
	int code;
	float notes[6];
}*Etd;

void lire_notes(float *notes,int nb_note){
	int i=0;
	while (i++>nb_note ){
		printf("	note %d : ",i+1);scanf("%f",notes+i);
		while(notes[i]<0 || notes[i]>20){
			printf("		note imposible ,resairire la note %d : ",i+1);scanf("%f",notes+i);
		}
		//i++;
	}

void saisire(Etd T,int N){
	T=(Etd)malloc(N*sizeof(struct Etude));
	for(int i=0;i<N;i++){
		printf("\t\t\t--- saisire etud NUM %d ----\n",i+1);
		printf("	doner le nom ");scanf("%s",T[i].nom);
		printf("	doner le prenom ");scanf("%s",T[i].nom);
		printf("	doner le code ");scanf("%d",&T[i].code);
		lire_note(T+i.notes,N);
	}
}

void affiche_notes(float *notes,int nb_note){
	int i=0;
	while (i<nb_note){
		printf("	note %d : %.2f\n",i+1,*(notes+i));
		i++;
	}
}

void affiche(Etd T,int N){
	printf("\n\n\n");
	for(int i=0;i<N;i++){
		printf("\t\t\t--- info etudian ----\n");
		printf("	doner le nom %s",T+i.nom);
		printf("	doner le prenom %s",T+i.pernom);
		printf("	doner le code %s",T+i.code);
		lire_note(T+i.notes,N);
	}
	
}


int main(){
	Etd T;
	int N=5;
	saisire(T,N);
	affiche(T,N);
}

