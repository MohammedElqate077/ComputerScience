#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max_etudian 1000

typedef struct La_Date{
	int jour;
	int moi;
	int anne;
}Date;

typedef struct Les_Etudiant {
	int matricule;
	char nom[20];
	char prenom [20];
	Date naissanse;
	float moyen;
}Etudiant;
 
typedef struct Le_Tab_etud {
	int nb_etu;
	Etudiant etudiant[1000];
}Tab_etud;

void saisire_etud(Etudiant *);
void ajout_etud(Tab_etud *,int N);
void affiche_etud(Etudiant etud);
void affecter(Etudiant *e1,Etudiant e2);
void echange(Etudiant *e1,Etudiant*e2);
int get_min(Etudiant *etud,Tab_etud *Tab);
void tri_nom(Tab_etud *);
void main (){
	int i,nb;	
	Tab_etud *T=(Tab_etud *)malloc(sizeof(Tab_etud));
	printf("\ttdonner le nombre de les etudiants : ");scanf("%d",&nb);
	for(i=0;i<nb;++i){
			printf("saisire l\'etudiant num %d\n",i+1);
			ajout_etud(T,i);
	}
	printf("\t\t ** l'etudiants triee ** \n");
	tri_nom(T);
	for(i=0;i<nb;++i){
			printf("\t\t etudiant num %d\n",i+1);
			affiche_etud(T->etudiant[i]);
	}
}

void saisire_etud(Etudiant *etud){
	printf("entrer matricule : ");scanf("%d",&etud->matricule);
	printf("entrer le nom : ");scanf("%s",etud->nom);
	printf("entrer prernom : ");scanf("%s",etud->prenom);
	printf("entrer << jour,moi et l'anne >> (respictivment): ");scanf("%d%d%d",&etud->naissanse.jour,&etud->naissanse.moi,&etud->naissanse.anne);
	printf("entrer le moyen : ");scanf("%f",&etud->moyen);
}

void affiche_etud(Etudiant etud){
	printf("matricule : %d",etud.matricule);
	printf("nom : %s",etud.nom);
	printf(" prernom : %s",etud.prenom);
	printf("date : %d/%d/%d",etud.naissanse.jour,etud.naissanse.moi,etud.naissanse.anne);
	printf(" moyen : %.2f",etud.moyen);
}

void ajout_etud(Tab_etud *Tab,int N){
	if (N >= 1000){
		printf("pas de place\n");
		exit(-1);
	}
	saisire_etud(&Tab->etudiant[N]);
	Tab->nb_etu++;
}
void affecter(Etudiant *e1,Etudiant e2){
	e1->matricule=e2.matricule;	
	strcpy(e1->nom,e2.nom);
	strcpy(e1->prenom,e2.prenom);
	e1->naissanse.jour=e2.naissanse.jour;
  	e1->naissanse.moi=e2.naissanse.moi;
  	e1->naissanse.anne=e2.naissanse.anne;
	e1->moyen=e2.moyen;	
}

void echange(Etudiant *e1,Etudiant*e2){
	Etudiant temp;
	affecter(&temp,*e1);
	affecter(e1,*e1);
	affecter(e2,temp);
}

int get_min(Etudiant *etud,Tab_etud *Tab){
	int imin=etud-(Tab->etudiant);
	Etudiant *temp=etud+1;
	while(temp < Tab->etudiant+Tab->nb_etu){
		if (strcmp(temp->nom,(temp+imin)->nom)>0){
			temp=temp+imin;
		}
		imin++;
	}
}

void tri_nom_select(Tab_etud *Tab){
	Etudiant *temp;
	int min_e;	
	for(temp = Tab->etudiant;temp < Tab->etudiant+Tab->nb_etu-1;temp++){
		min_e=get_min(temp,Tab);
		if(temp !=(Tab->etudiant+min_e)){ 
			echange(temp,Tab->etudiant+min_e);
		}
	}
}