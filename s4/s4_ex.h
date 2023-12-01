#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define maxnote 10

#define is_redoublement(a) (a?puts("oui"):puts("nom"))



typedef struct {
	int jour;
	char moi[10];
	int anne;
}Date;

typedef struct {
	char nom[15];
	char prenon[15];
	Date naissance;
	char formation[3];
	char redoublement;
	int td;
	int nb_note;
	float notes[maxnote];
	int note_valid;
}fiche;

float moyenne_notes(fiche *fi);

void lire_date(Date *element){
	printf("	jour	: ");scanf("%d",&element->jour);
	printf("	moi : ");scanf("%s",element->moi);
	printf("	anne : ");scanf("%d",&element->anne);

}

void lire_notes(float *notes,int *note_valid,int nb_note){
	*note_valid=0;
	int i=0;
	while (i<nb_note){
		printf("		note %d : ",i+1);scanf("%f",notes+i);
		if(*(notes+i) >= 10){
			 (*note_valid)++;
		}
		i++;
	}
}

void ajoute_notes(fiche *fi){
	if(fi->nb_note < maxnote)
	lire_notes(fi->notes,&fi->note_valid,fi->nb_note);
}

fiche *lire_fiche(fiche *fi){
	printf("	nom : ");fgets(fi->nom,15,stdin);//scanf("%s",fi->nom);
	printf("	prenon : ");fgets(fi->prenon,15,stdin);
	lire_date(&fi->naissance);
	printf("	formation : ");scanf("%s",fi->formation);
	printf("	group de td : ");scanf("%d",&fi->td);
	printf("	redoublement (o si oui n si non): ");scanf(" %c",&fi->redoublement);
	printf("	nb des notes (max %d) : ",maxnote);scanf(" %d",&fi->nb_note);
	ajoute_notes(fi);
	return fi;
}

void affiche_notes(float *notes,int nb_note){
	int i=0;
	while (i<nb_note && nb_note < maxnote){
		printf("		note %d : %.2f\n",i+1,*(notes+i));
		i++;
	}
}
void ecrire_fiche(fiche *fi){
	char n_o;
	//float moyen=moyenne_notes(fi);

	printf("	nom : %s ",fi->nom);
	printf("	prenon : %s ",fi->prenon);
	printf("	date de naissance j/m/a : %d / %s / %d\n",fi->naissance.jour,fi->naissance.moi,fi->naissance.anne);
	printf("	formation : %s\n",fi->formation);
	printf("	group de td : %d\n",fi->td);
	printf("	redoublement : ");is_redoublement(fi->redoublement=='o');//?puts("oui"):puts("nom");
	printf("	nombre note valide %d\n",fi->note_valid);
	printf("	affiche la moyen (o si oui ,n si nom) : ");scanf(" %c",&n_o);
	if( n_o=='o' || n_o=='O'){
		printf("		le moyen : %.2f\n",moyenne_notes(fi));
	}
	printf("	affiche notes ou nom(o si oui ,n si nom) : ");scanf(" %c",&n_o);
	if( n_o=='o' || n_o=='O'){
		affiche_notes(fi->notes,fi->nb_note);
	}
}

float moyenne_notes(fiche *fi){
		int i=0;
		float some=0;
		while( i < maxnote ){
			some+=*((fi->notes)+i);
			i++;
		}
		return some/fi->nb_note;
}





