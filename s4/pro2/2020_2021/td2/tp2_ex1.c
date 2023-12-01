/*
 * MOHAMMED
 * GR : 2
 * 2020/2021
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

char* allouer_string(int n){
	char *res = (char *)malloc(n*sizeof(char));
	return res;
}

char* adn_sequience(int n){
	char nucles[4] = { 'A','C','G','T'}; 
	char *res=allouer_string(n);
	for (int i = 0; i < n; i++){
		res[i] =nucles[(rand() % 4)];
	}
	return	res;
}

void affiche_adn(char *res,int n){
	//fputs(res,stdout);
	for(int i=0;i<n;i++){
		printf("%c",*(res+i));
	}
	printf("\n");
}

void compte_nucle_adn(char *res){
	puts("\n\t\t --- affichage le nb de chaque nucliere ADN ---");
	char *pt=res;
	int nb_A=0,nb_C=0,nb_G=0,nb_T=0;
	while(*pt!='\0'){
		switch(*pt){
			case 'A': nb_A++;break;
			case 'C': nb_C++;break;
			case 'G': nb_G++;break;
			case 'T': nb_T++;break;
		}	
		pt++;
	}
	
	printf(" nb_A=%d\t\t nb_C=%d\n nb_G=%d\t\t nb_T=%d\n",nb_A,nb_C,nb_G,nb_T);

}

char *complement_ADN(char *res){
	char *com_ADN=allouer_string(strlen(res));
	int i=0;
	while(res[i]!='\0'){
		switch(res[i]){
			case 'A': *(com_ADN+i)='T';break;
			case 'C': *(com_ADN+i)='G';break;
			case 'G': *(com_ADN+i)='C';break;
			case 'T': *(com_ADN+i)='A';break;
		}	
		i++;
	}
	return com_ADN;	
}
char *codones(char *res,int n){
	int i=0;
	char *triplet=allouer_string(((n/3)+(n%3))*3);
	for(int k=i=0;i<((n/3)+(n%3)),k<n;i++,k++){
		for(int j=0;j<3;j++){
			triplet[i]=res[k];
		}
	}
	return triplet;
}

void affiche_codones(char *res,int n){
	for(int i=1;i<n+1;i++){
		printf("%c",res[i-1]);
		if(i%3==0) printf("  ");
	}
	printf("\n");
}

void affiche_mat(char *M,int l,int c){
	int i,j;	
	for (i=0;i<l;++i){
		for(j=0;j<c;++j){
			printf("%c",*(M+i*c+j));
		}
		printf("  ");
	}
}

int *codon_start(char *adn){
	
	int *pos=(int *)malloc(((strlen(adn)/3)+strlen(adn)%3)*sizeof(int));
	int nb_pos=-1;
	for(int i=0;i<strlen(adn);i=i+3){
		if (strncmp(adn+i,"AGT",3)==0){
			nb_pos++;
			*(pos+nb_pos)=i;
		}
	}
	if (nb_pos<=0){
		printf("la codone ne existe pas\n");
		free(pos);
		pos=NULL;
		return NULL;
	}else{
		nb_pos++;
		pos=(int *)realloc(pos,(nb_pos)*sizeof(int));

		printf("le nb des position %d de la codone AGT est sont ",nb_pos);
		for (int i=0;i<nb_pos;++i)
			printf(" %d ",*(pos+i));
		printf("\n");
		return pos;	
	}
}
int codon_stop(char *adn,int *j ){
	/*if (j==NULL){
		printf("on ne peut pas faire la rechaire , codone strt return rien (NULL)\n");
		return -1;
	}*/
	int i;	
	int pos=-1;
	for(i=0;i<strlen(adn);i=i+3){
		if (strncmp(adn+i,"TAG",3)==0){
			pos=i;
			break;
		}
	}
	if (pos==-1 || j==NULL){
		printf(" ne recontre rien la codone TAG\n");
		return -1;
	}else{
		printf(" on recontre la premier codone < TAG > apre l\'indice %d dans la pos %d\n",*(j+0),pos);
		return pos;	
	}
}
char *suprimer_duplic(char *adn,int taille){
	int new_taille=0;
	char *new_codones=(char *)malloc(((strlen(adn)/3)+strlen(adn)%3)*sizeof(char));
	char *trip=(char *)malloc(3*sizeof(char));
	for(int i=0;i<taille;i=i+3){
		strncpy(trip,adn+i,3);
		if (strstr(new_codones,trip)==NULL){
			strcat(new_codones+new_taille,trip);
			new_taille+=3;
		}
	}
	if(taille==new_taille)
		printf("ne suprime rien");return new_codones;
	return (char *)realloc(new_codones,(new_taille)*sizeof(char));

}

int main(){
	int n;
	time_t t;
	srand(t);
	printf("la langoure N de l\'adn : ");scanf("%d",&n);

	char *ADN=allouer_string(n);
	ADN=adn_sequience(n);
	puts("\t\t --- affichage de ADN genere ---\n");
	affiche_adn(ADN,n);

	compte_nucle_adn(ADN);

	puts("\t\t --- affichage le complement de ADN ---\n");
	affiche_adn(complement_ADN(ADN),n);
	
	puts("\t\t --- affichage les cadones extraie de ADN ---\n");
	char *triplet=allouer_string((n/3)+(n%3)*3);
	triplet=codones(ADN,n);
	affiche_mat(triplet,(n/3)+(n%3),3);

	puts("\n\t\t --- affichage 2 cadones (nom extrair _seule affichage) --- \n");
	affiche_codones(ADN,n);
	
	puts("\n\t\t --- codones start --- \n");
	int *cod_start=codon_start(ADN);

	puts("\n\t\t --- cadones stop --- \n");
	int cod_stop=codon_stop(ADN,cod_start);

	triplet=suprimer_duplic(triplet,strlen(triplet));
	puts("\t\t --- affichage les cadones de ADN non duplicate---\n");
	
	affiche_codones(triplet,strlen(triplet));

	//if(strstr("my_mac_book","hhhhhh")==NULL)
	//	printf("raha sd9at\n");
	
	return 0;
}

