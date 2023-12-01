#include <stdio.h>
#include<stdlib.h>
int main(){
	int i,n,existe=0;
	printf("entrer un entier strictement positif\n");
	scanf("%d",&n);
	for (i=2;i<=n-1;i++){
		if(n%i==0)
			existe++;
	}
	if (existe==0)
		printf("%d est un nombre premier\n",n);
	else printf("%d n'est pas un nombre premier\n",n);

}

/*
algorithme	nb_premier
variables	i,n,existe	:entier
debut
	ecrire("entrer un entier strictement positif")
	lire(n)
	existe=0
	pour (i=2 a n-1) faire
		si ( n%i != 0) alors
			existe<--existe+1
		finsi
	fin_pour
	si(existe=0) alors
		ecrire(n," est un nombre premier")
	sinon
		ecrire(n," n'est pas un nombre premier")
	finsi 
fin	
*/
