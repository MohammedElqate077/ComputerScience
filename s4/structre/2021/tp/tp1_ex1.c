#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

typedef struct La_date{
	int jour;
	char moi[10];
	int anne;
}Date;

void lire_date(Date *element){
	printf("donner le jour ");scanf("%d",&element->jour);
	printf("donner le moi ");scanf("%s",element->moi);
	printf("donner le anne ");scanf("%d",&element->anne);

}

void affiche_date(Date *element){
	printf("le jour est %d\n",element->jour);
	printf("le moi est %s \n",element->moi);
	printf("le anne est %d\n",element->anne);
}

int main (){
	Date e;	
	printf("done les info de date\n");
	lire_date(&e);
	printf("les resulta\n");
	affiche_date(&e);
	return 0;

}
