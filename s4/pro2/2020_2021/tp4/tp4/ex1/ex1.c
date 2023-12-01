/*
 * 2021
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define texte /home/text.txg

void ecrire_c_file(FILE *F){
	char c;
	printf("\n ** ecrire file\n\n");
	F=fopen("texte","w");
	if(F==NULL){
		printf("oops eroor opning\n");
		//exit(1);
		EXIT_FAILURE;
	}
	while (c!=EOF){
		c=getchar();
		fputc(c,F);
	}
	fclose(F);
}

void affiche_c_file(FILE *F){
	char c;
	printf("\n ** affichage file\n\n");
	while((c=fgetc(F))!=EOF)	{
		//printf("%c",c);
		putchar(c);
	}
	fclose(F);
	return;
}

int nb_carac_file(FILE *F){
	int nb_c=0;
	while(fgetc(F)!=EOF)	{
		nb_c++;
	}
	fclose(F);

	printf("\n ** le nb de caractere de ce file est %d\n\n",nb_c);
	return nb_c;
}

void nb_voyel(FILE *F){
	char X;
	unsigned int nb_a=0,nb_e=0,nb_i=0,nb_o=0,nb_u=0;
	while((X=fgetc(F))!=EOF)	{
		switch(X){
		case 'a': nb_a++ ;break;
		case 'e': nb_e++ ;break;
		case 'i': nb_i++ ;break;
		case 'o': nb_o++ ;break;
		case 'u': nb_u++ ;break;
		}
	}
	printf("nombre de a %d\n",nb_a);
	printf("nombre de e %d\n",nb_e);
	printf("nombre de i %d\n",nb_i);
	printf("nombre de o %d\n",nb_o);
	printf("nombre de u %d\n",nb_u);
	fclose(F);
}


int nb_mots(FILE *F){
	char X;
	unsigned int nb_mot=0;
	while((X=fgetc(F))!=EOF){
		if(X==' ' || X=='\n')
			nb_mot++;
	}
	printf("\n ** nombre de mot %d\n\n",nb_mot);
	fclose(F);
	return nb_mot;
}

int is_palindrom(char *R,int i,int n){
	
	if(R[i]!=R[n]){
		return 0;
	}
	if (i>n){//i>=n
			return 1;
	}
	return is_palindrom(R,++i,--n);
}

int palindrome(char *R,int n){
	int i=0;
	while(i<n){	
		if(R[i]!=R[n]){	
			return 0;
		}
		i++;			
		n--;	
	}
	return 1;
}


void affiche_palindrom (FILE *F){//verfier si le premier caratere espace ou newline (3ad rditlha elbal,donc initialisi elhaja)
	char X;
	char pali[10];
	int i;

	printf("\n ** affichage de mot de palindrome \n\n");
	
	start:
	i=0;
	while((X=fgetc(F))!=EOF){//chouf had le code pali[i]=X;i++; wdwzha b palindrome[pali,i-1]// mais ma testitouch bach thl lprobleme la jat flwl
		if(X==' ' || X=='\n'){
			//pali[i]='\0';
			if(palindrome(pali,i))
				printf(" %s",pali);
			//i=-1;
			goto start;
		}
		pali[i]=X;
		i++;
	}
	fclose(F);
}

int main(){
	FILE *F=NULL;
	int nb_c;
	int nb_mot;

	ecrire_c_file(F);

	F=fopen("texte","r");
	affiche_c_file(F);

	F=fopen("texte","r");
	nb_c=nb_carac_file(F);
	F=fopen("texte","r");
	nb_voyel(F);

	F=fopen("texte","r");
	nb_mot=nb_mots(F);

	F=fopen("texte","r");
	affiche_palindrom(F);
	return 0;
}
