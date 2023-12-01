// ERREURE EN EXECUTION


#include<stdio.h>
#include<stdlib.h>
//#define pi=3,14
int main (){
	float r,l,h,a,b,S;
	char ch;
	printf("***calcule de surface***\n");
	printf("C : Cercle\n");
	printf("T : Triengle\n");
	printf("R : Rectengle\n");
	printf("taper votre choix : C,R ou T\n");
	scanf("%c",&ch);
	
//	do{
		if( ch=='C' || ch=='c'){
			printf("enter la valeure de rayon(r)\n");
			scanf("%f",&r);
			// const float pi=3,14
			// S=pi*r*r
			S=3,14*r*r;
			printf("la surface du cercle est %f\n",S);
		}
		else{
			if(ch=='T' || ch=='t'){
			 	printf("enter les valeures de a et b respictivment\n");
				scanf("%f%f",&a,&b);
				S=(a*b)/2;
				printf("la surface du triengle est %f\n",S);
			}
			else {
				if(ch=='R' || ch=='r'){
					printf("entre les valeures de l et h respictivment\n");
					scanf("%f%f",&l,&h);
					S=l*h;
					printf("la surface du rectengle est %f\n",S);
				}
				else printf("erreur de saisire\n");
			}
		
		}

		printf("***calcule de surface***\n");
	 	printf("C : Cercle\n");
	 	printf("T : Triengle\n");
	 	printf("R : Rectengle\n");
		printf("taper votre choix : C,R ou T\n");
		printf("taper Q ou q si vous voulez quiter\n");
//		scanf("%c",&ch);
		
//	}while(ch!='Q' || ch!='q');
}


/*
#include<stdio.h>
#include<stdlib.h>
//#define pi=3,14
int main (){
	float r,l,h,a,b,S;
	char ch;
	printf("***calcule de surface***\n");
	printf("C : Cercle\n");
	printf("T : Triengle\n");
	printf("R : Rectengle\n");
	printf("taper votre choix : C,R ou T\n");
	scanf("%c",&ch);
	
	while (ch!='Q' || ch!='q'){
		if( ch=='C' || ch=='c'){
			printf("enter la valeure de rayon(r)\n");
			scanf("%f",&r);
			// const float pi=3,14
			// S=pi*r*r
			S=3,14*r*r;
			printf("la surface du cercle est %f\n",S);
		}
		else{
			if(ch=='T' || ch=='t'){
			 	printf("enter les valeures de a et b respictivment\n");
				scanf("%f%f",&a,&b);
				S=(a*b)/2;
				printf("la surface du triengle est %f\n",S);
			}
			else {
				if(ch=='R' || ch=='r'){
					printf("entre les valeures de l et h respictivment\n");
					scanf("%f%f",&l,&h);
					S=l*h;
					printf("la surface du rectengle est %f\n",S);
				}
				else printf("erreur de saisire\n");
			}
		
		}

		printf("***calcule de surface***\n");
	 	printf("C : Cercle\n");
	 	printf("T : Triengle\n");
	 	printf("R : Rectengle\n");
		printf("taper votre choix : C,R ou T\n");
		printf("taper Q ou q si vous voulez quiter\n");
		scanf("%c",&ch);
		
	}
}
*/





// ALGORITHME

/*
algorithme:	surface_affiche
variables:	r,l,h,a,b,S:	reel
			ch:				caratere
debut
	ecrire ("***calcule de surface***")
	ecrire ("C : Cercle")
	ecrire ("T : Triongle")
	ecrire ("R : Rectengle")
	ecrire ("taper votre choix : C,R ou T")
	lire (ch)
	tant_que (ch != Q ou ch != q) faire	
		si (ch=C ou ch=c) alors
	 		ercrie ("enter la valeure de rayon(r)")
			lire (r)
			// const pi=3,14
			// S<--pi*r*r
			S<--3,14*pi*pi
			ecrire ("la surface du cercle est ",S)
			sinon 
				si (ch=T ou ch=t) alors
					ecrire ("enter les valeures de a et b respictivment")
					lire (a,b)
					S<--(a*b)/2
					ecrire ("la surface du triengle est ",S)
					sinon
						si (ch=R ou ch =r) alors
							ecrire ("enter les valeures de l et h respictivment")
							lire (l,h)
							S<--l*h
							ecrire ("la surface du rectengle est ",S)
							sinon 
								ecrire ("erreur d'enter")
						finsi
				finsi
		finsi

	ecrire ("***calcule de surface***")
	ecrire ("C : Cercle")
	ecrire ("T : Triongle")
	ecrire ("R : Rectongle")
	ecrire ("Q : pour quite")
	ecrire ("taper votre choix : C,R,T ouQ")
	lire (ch)

	fintq
fin
*/

