//  ERREURE EN EXECUTION de 2 code apres cette partie

#include<stdio.h>
#include<stdlib.h>
int main(){
	int i,nb;
	float some=0,note,moy;
	printf("entrer le nombre des notes\n");
	scanf("%d",&nb);
	
	i=1;
	while(i<=nb) {		 
		printf("enter la note %d\n",i);
		scanf("%f",&note);
		while (note<0 || note>20){
			printf("entrer une note tq 0<=note<=20\n");
			scanf("%f",&note);
		}		
		some+=note;
		i=i+1;
	}
	moy=some/nb;
	printf("le moyen des notes est %.2f\n",moy);
}



/*
#include<stdio.h>
#include<stdlib.h>
float main(){
	int i,nb;
	float some,note,moy;
	printf("entrer le nombre des notes\n");
	scanf("%d",&nb);
	some=0;
	for (i=1 ; i=nb; i++){
		printf("enter la note %d\n",i);
		scanf("%f",&note);
		while (note<0 || note>20){
			printf("entrer une note tq 0<=note<=20\n");
			scanf("%f",&note);
		}
		some+=note;
	}
	moy=some/nb;
	printf("le moyen des notes est %f\n",moy);
}
*/

/*
#include<stdio.h>
#include<stdlib.h>
int main(){
	int i,nb;
	float some,note,moy;
	printf("entrer le nombre des notes\n");
	scanf("%d",&nb);
	some=0;
	i=1;
	do {		 
		printf("enter la note %d\n",i);
		scanf("%f",&note);
		while (note<0 || note>20){
			printf("entrer une note tq 0<=note<=20\n");
			scanf("%f",&note);
		}		
		some+=note;
		i=i+1;
	}while(i=nb);
	moy=some/nb;
	printf("le moyen des notes est %f\n",moy);
}
*/