#include"pile.h"
#include<string.h>
#include<unistd.h>


bool valid(char *C){
	int i=0;
	Pile *P=create_pile();
	while(C[i]!='\0'){

		if( C[i]=='[' || C[i]=='(' || C[i]=='{' ){
				empile_pile(P,&C[i]);
		}
		else if( C[i]==']') {
			if (sommet(P)==NULL ||  *sommet(P)!='[' || est_vide(P)) return false;
			else	dipiler_pile(P);
		}
		else if (C[i]==')'){
			if (sommet(P)==NULL ||  *sommet(P)!='(' || est_vide(P)) return false;
			else	dipiler_pile(P);
		}
		else if( C[i]=='}') {
			if (sommet(P)==NULL ||  *sommet(P)!=':' || est_vide(P)) return false;
			else	dipiler_pile(P);
		}

		i++;
	}
	return est_vide(P);
}

int main(){

	char *C=(char*)calloc(60,sizeof(char));

	puts("\t\t *** enter l\'expression *** \n");
	fgets(C,60,stdin);
	
	C=(char*)realloc(C,strlen(C)*sizeof(char));
	
	printf("l\'expretion est %s\n",valid(C)?"valide":"non valide");
	return 0;
}
