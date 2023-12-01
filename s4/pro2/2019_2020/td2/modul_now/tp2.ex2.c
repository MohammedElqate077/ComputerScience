#include<stdio.h>
#include"tp2.ex2.h"

int main(){
	int N;	
	printf("donne le nb de les employer : ");scanf("%d",&N);
	Empl *emp=crea_tab_emp(N);
	emp=saisire_tab_emp(N);
	affiche_tab_empl(emp,N);
}
