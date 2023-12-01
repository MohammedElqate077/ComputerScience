/*
 * 2021
*/

#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>  

typedef struct Etudient{  
	char nom[15];  
	char prenom[15];  
	char CNE[10];  
	float CC,TP,CF;  
	float moy;
}Etud;  

Etud info_etud(Etud etd){  
	
	printf("\t\tnom:");  
	scanf("%s",etd.nom);  
	printf("\t\tprenom:");  
	scanf("%s",etd.prenom);  
	printf("\t\tCNE:");  
	scanf("%s",etd.CNE);  
	printf("\t\tNOTES (respictivement CC CF TP) :");  
	scanf("%f %f %f",&etd.CC,&etd.CF,&etd.TP);  
	
	return etd;  
}  

Etud* saisire_etud(Etud* T,int N){  

	T=(Etud*)malloc(N*sizeof(Etud));  
	for(int i=0;i<N;i++){  
		printf("\t\t INFO ETUD NUM: %d\n",i+1);  
		T[i]=info_etud(T[i]);  
  
	}
	return T;  
}  

void ecrire_fichier(Etud* T, int N, char *ch){  
	int i;  
	FILE* f;
	f=fopen(ch,"w");  
	if(f==NULL) 
		printf("erreur d'ouverture\n");  
	else{  
		fwrite(T,sizeof(Etud),N,f);  
	}  
	fclose(f);  
}  

void Ajout_etudient( Etud etd, char *ch){  
	int i;  
	FILE* f;
	f=fopen(ch,"a");  
	if(f==NULL) 
		printf("erreur d'ouverture\n");  
	else{  
		etd=info_etud(etd);
		fwrite(&etd,sizeof(Etud),1,f);  
		fclose(f);  
	}  
}  

void Afficher(Etud* T, int N){  
	int i;  
	for(i=0;i<N;i++){  
		printf("\n\t\t *** AFFICHE INFO ETUD NUM %d\n",i+1);
		printf("\tnom  :%s\n",T[i].nom);  
		printf("\tprenom  :%s\n",T[i].prenom);  
		printf("\tCNE : %s\n",T[i].CNE);  
		T[i].moy=((0.5*T[i].CF+0.3*T[i].CC+0.2*T[i].TP));  
		printf("\tmoyen generale :%5.2f\n",T[i].moy);  
	}
}  

void Rechercher(Etud* T,int N,char* CNE){  
	int i;  
	for(i=0;i<N;i++){  
		if(strcmp(CNE,T[i].CNE)==0){  
			printf("\n\t\tl'etudient cherché est :%s\n",T[i].nom);
		}  
  
	}
}  

void ListeRattrapage(Etud* T,int N){  
	int i;  
	printf("\n\n\t\tetudients convoce au ratrapage est :\n");  
	for(i=0;i<N;i++){  
		if(T[i].CC<10||T[i].CF<10||T[i].TP<10){  
			printf("\t %s  %s \n",T[i].nom,T[i].prenom);  
		}  
	}  
}  

void modifierNote(Etud* T,int N,char* CNE){  
	int i;  
	for(i=0;i<N;i++){  
		if(strcmp(CNE,T[i].CNE)==0){  
			T[i].CC=18; 	 
			T[i].CF=20;  
			T[i].TP=19;  
		}  
	}  
}  

void retrouve_info(Etud* T,int N,char* CNE){  

	for(int i=0;i<N;i++){  
		if(strcmp(CNE,T[i].CNE)==0){  
			printf("\tnom  :%s\n",T[i].nom);  
			printf("\tprenom  :%s\n",T[i].prenom);  
			printf("\tCNE : %s\n",T[i].CNE);  
			printf("\tmoyen generale :%5.2f\n",T[i].moy);  
		}
	}
}  

int main(){  
	Etud* T;  
	int N;  
	char CNE[10];  

	printf("\n\tEntrer la taille du tableau:");  
	scanf("%d",&N);  


	T=saisire_etud(T,N);  
	Afficher(T,N);  

	Rechercher(T,N,CNE);  
	modifierNote(T,N,CNE);  

	ListeRattrapage(T,N); 

	printf("\n\tdonner le CNE du l'etudient a cherche:");  
	scanf("%s",CNE);  
	retrouve_info(T,N,CNE);  

	ecrire_fichier(T,N,"ex2.txt");  
	Etud etd=info_etud(etd);  
	Ajout_etudient(etd,"ex2.txt"); 

}
