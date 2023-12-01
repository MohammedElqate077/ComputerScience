#include<stdio.h>

int main(){

	int pos=0,neg=0,n,i;
	float nb,some=0,pro=1,moy;

	printf("entrer le nombre des nombre\n");
	scanf("%d",&n);

	for(i=1;i<=n;i++){
		printf("entrer le nombre numero %d\n",i);
		scanf("%f",&nb);

		if(nb>0){
			pos+=1;
			some+=nb;
		}
		else{
			if(nb<0)
				neg+=1;
				pro*=nb;
		}
	}
	if(pos>0){
		moy=some/pos;
		printf("la moyen des nombre positives est %.2f\n",moy);
	}
	else{ 
		printf("pas des nombre prositves\n");
	}
	
	if(neg>0){
		printf("le produit des nombres negatives est %.2f\n",pro);
	}
	else{
		printf("pas des nombre negative\n");
	}

}



/*
algorithme  moy_pos_prod_neg
variables	nb,som,pro,moy  : reel
			pos,neg,n,i				:entier
debut
	ecrire("entrer le nombre de nb")
	lire(N)
	som=0
	pro=1
	pos=0
	neg=0
	pour (i=1 a n) faire
		ecrire("entrer le nombre numero",i)
		lire(nb)
		si (nb>0) alors
			pos=pos+1
			som=som+nb
		  sinon
		  	si (nb<0) aloes
		  		neg=neg+1
		  		pro=pro*nb
		  	finsi
		finsi
	fin_pour
	si (pos>0)alors
		moy=moy/pos
		ecrire("la moyen des nombre positives est ",moy)
	  sinon 
	  	ecrire("pas des nombre prositves")
	si (neg>0) alors
		ecrire("le produit des nombre negative est ",pro)
	  sinon
	    ecrire("pas des nombres negatives")
fin
*/



