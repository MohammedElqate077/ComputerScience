#include<stdio.h>
#include<stdlib.h>

int dim();
void saisire(double T[],int a);
double prod(double A[],double B[],int a);
void affiche(double a);

void main(){
	//declaration de variable locale du fonction main
	int i,n;
	double res=0;

	// la valeur de dimention n
	n=dim();

	double U[n],V[n];

	//saisire les tableau
	saisire(U,n);
	saisire(V,n);	
	
	//le produie scalaire
	res=prod(U,V,n);
	
	//affiche de resultat
	affiche(res);

}

int dim(){
	int n;
	printf("entrer dimention du U et V (max 50) : ");
	scanf("%d",&n);
	return n;
}

void saisire(double T[],int a){
	for(int i=0;i<a;i++){
		printf("entrer la valer %d=",i);
		scanf("%lf",&T[i]);
	}
}

double prod(double A[],double B[],int a){
	double sca;
	for(int i=0;i<a;i++)
		sca+=(double)(A[i]*B[i]);
	return sca;
}

void affiche(double a){
	printf("le produit scalaire de 2 vecteur est %.2lf\n",a);
}



/* 

// ===== avec variable globale ===== 

#include<stdio.h>
#include<stdlib.h>

//declaration des variable globale du programe
int i,n;
double res=0;

// fontion prototype
void dim();
void saisire(double T[],int a);
void prod(double A[],double B[],int a);
void affiche(double a);

void main(){

	// la valeur de dimention n
	dim();

	double U[n],V[n];

	//saisire les tableau
	saisire(U,n);
	saisire(V,n);	
	
	//le produie scalaire
	prod(U,V,n);
	
	//affiche de resultat
	affiche(res); c
}

void dim(){
	printf("entrer dimention du U et V (max 50) : ");
	scanf("%d",&n);
}

void saisire(double T[],int a){
	for(i=0;i<a;i++){
		printf("entrer la valer %d=",i);
		scanf("%lf",&T[i]);
	}
}

void prod(double A[],double B[],int a){
	for(i=0;i<a;i++)
		res+=(double)(A[i]*B[i]);
}

void affiche(double a){
	printf("le produit scalaire de 2 vecteur est %.2lf\n",a);
}


// =================================================================================


// ===== programe normale ======
#include<stdio.h>
#include<stdlib.h>

void main(){
	int i,n;
	double res=0;
	// la valeur de dimention n
	printf("entrer dimention du U et V (max 50) : ");
	scanf("%d",&n);

	double U[n],V[n];

	//saisire les tableau
	for(i=0;i<n;i++){
		printf("entrer la valer U[%d]=",i);
		scanf("%lf",&U[i]);
	}

	for(i=0;i<n;i++){
		printf("entrer la valer V[%d]=",i);
		scanf("%lf",&V[i]);
	}


	//le produie scalaire

	for(i=0;i<n;i++){
		res+=(double)(U[i]*V[i]);
	}

	//affiche de resultat

	printf("le produit scalaire de 2 vecteur est %.2lf\n",res);
}

*/
