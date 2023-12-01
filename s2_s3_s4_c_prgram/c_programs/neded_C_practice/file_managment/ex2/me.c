#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>


typedef struct {
	char nom [20];
	char prenom [20];
	char CNE [10];
	float CC,CF,TP;
	float moyen;
}Etud;

void read_etud(Etud *e){
	printf("enter donner des etudiant\n");
	printf("nom / prenom:");scanf("%s%s",e->nom,e->prenom);
	printf("CNE:");scanf("%s",e->CNE);
	printf("CC / CF / TP:");scanf("%f%f%f",&e->CC,&e->CF,&e->TP);
	e->moyen=(e->CC*0.5+e->CF*0.3+e->TP*0.2);
	//e->moyen=((e->CC*0.5)+(e->CF*0.3)+(e->TP*0.2));
}


int inser_etud(char *path){
	FILE *F=NULL;
	F=fopen(path,"a");
	printf("\n\t\t*** AJOUTE ETUDIANT ***\n");
	Etud *e=(Etud*)malloc(sizeof(Etud));
	read_etud(e);
	if (F==NULL){
		printf("error open file for add etud\n");
		return -1;
	}
	else{
		fprintf(F,"%s %s\t%s\t\t%4.2f %4.2f %4.2f\t%4.2f\n",e->nom,e->prenom,e->CNE,e->CC,e->CF,e->TP,e->moyen);
	}
	e=NULL;
	free(e);
	fclose(F);
	return 0;
}


int affiche_etud(char *path){
	FILE *F=NULL;
	printf("\n\t\t*** AFFICHAGE ETUDIANTS ***\n");
	Etud *e=(Etud*)malloc(sizeof(Etud));
	//if()
	F=fopen(path,"r");
	if (F==NULL){
		printf("error open file for read etud");
		return -1;
	}
	else{
		while(!feof(F)){
			fscanf(F,"%s %s\t\t%s\t%f %f %f\t%f",e->nom,e->prenom,e->CNE,&e->CC,&e->CF,&e->TP,&e->moyen);
			printf("%s %s\t\t%s\tCC=%4.2f CF=%4.2f TP=%4.2f\tmoy=%4.2f\n",e->nom,e->prenom,e->CNE,e->CC,e->CF,e->TP,e->moyen);
		}
	}
	e=NULL;
	free(e);
	fclose(F);
	return 0;
}

Etud *search_etud(char *path){
	FILE *F=NULL;
	char CNE[10];
	int existe=0;
	Etud *e=(Etud*)malloc(sizeof(Etud));

	printf("\n\t\t*** RECHERCHE ETUDIANT ***\n");
	F=fopen(path,"r");
	printf("CNE a recher : ");scanf("%s",CNE);

	if (F==NULL){
		printf("error open file for search etud");
		return NULL;
	}
	else{
		while(!feof(F)){
			fscanf(F,"%s %s\t\t%s\t%f %f %f\t%f",e->nom,e->prenom,e->CNE,&e->CC,&e->CF,&e->TP,&e->moyen);
			if(strcmp(CNE,e->CNE)==0) return e;
		}
	}
	e=NULL;
	free(e);
	fclose(F);
	return NULL;
}

void list_ratt(char *path){
	FILE *F=NULL;
	int existe=0;
	Etud *e=(Etud*)malloc(sizeof(Etud));

	printf("\n\t\t*** LIST ETUDIANT RATRAPAGE ***\n");
	F=fopen(path,"r");

	if (F==NULL){
		printf("error open file for search etud");
		return ;
	}
	else{
		while(!feof(F)){
			fscanf(F,"%s %s\t\t%s\t%f %f %f\t%f",e->nom,e->prenom,e->CNE,&e->CC,&e->CF,&e->TP,&e->moyen);
			if(e->moyen<10){
			printf("%s %s\t\t%s\tCC=%4.2f CF=%4.2f TP=%4.2f\tmoy=%4.2f\n",e->nom,e->prenom,e->CNE,e->CC,e->CF,e->TP,e->moyen);
				existe=1;
			}
		}
	}
	if(existe==0) printf("\nliste ratrapage est vide\n");
	e=NULL;
	free(e);
	fclose(F);
	return ;

}

void modify_etud(char *path){
	FILE *F=NULL;
	FILE *F2=NULL;
	long ii2;
	char CNE[10];
	Etud *e=(Etud*)malloc(sizeof(Etud));
	printf("\n\t\t*** MODFIER ETUD ***\n");
	F=fopen(path,"r");
	F2=fopen(path,"r+");
	printf("CNE a recher : ");scanf("%s",CNE);
	if (F==NULL){
		printf("error open file for search etud");
		return ;
	}
	//if((e=search_etud(path))==NULL)	printf("l\'utudiant n'est existe pas pour modify\n");
	else{
		while(!feof(F)){
			ii2=ftell(F);
			fscanf(F,"%s %s\t\t%s\t%f %f %f\t%f",e->nom,e->prenom,e->CNE,&e->CC,&e->CF,&e->TP,&e->moyen);
			if(strcmp(CNE,e->CNE)==0){
				fseek(F,-ii2,SEEK_SET);
				printf("CC / CF / TP:");scanf("%f%f%f",&e->CC,&e->CF,&e->TP);
				e->moyen=(e->CC*0.5+e->CF*0.3+e->TP*0.2);
				fprintf(F2,"%s %s\t%s\t\t%4.2f %4.2f %4.2f\t%4.2f\n",e->nom,e->prenom,e->CNE,e->CC,e->CF,e->TP,e->moyen);
				break;
			}
			ii2=ftell(F);
		}
	}
	e=NULL;
	free(e);
	fclose(F);
	return ;

}
int main(){

	Etud *e=(Etud*)malloc(sizeof(Etud));
	inser_etud("etud.txt");
	affiche_etud("etud.txt");
	e=search_etud("etud.txt");
	if(e==NULL){
		printf("\netud n\'existe pas\n");
	}
	else 	printf("%s %s\t\t%s\tCC=%4.2f CF=%4.2f TP=%4.2f\tmoy=%4.2f\n",e->nom,e->prenom,e->CNE,e->CC,e->CF,e->TP,e->moyen);
	list_ratt("etud.txt");
		
	modify_etud("etud.txt");
	affiche_etud("etud.txt");
	return 0;
}
