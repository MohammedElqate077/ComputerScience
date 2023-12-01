#include<stdio.h>
#include<stdlib.h>
#include<string.h>

float *saisire(float *T,int N);
void affiche(float *T,int N);
int compte_nb(float *T,int N,char *what);
float *copy_table(float *T,int N,int N1,char *what);

float *saisire(float *T,int N){
	T=(float *)malloc(N*sizeof(float));
	if(T==NULL){
		printf("memoire nom allouer\n");
		exit(0);
	}
	else 			
		printf("memoire allouer avec succes\n");

	for (int i=0;i<N;i++){
		printf("entrer element num %d : ",i+1);
		scanf("%f",T+i);
	}
	return T;
}

/////

void affiche(float *T,int N){
	printf("T[%d]=",N);
	for (int i=0;i<N;++i)
		printf(" %.2f ",*(T+i));

	printf("\n");
}

////

int compte_nb(float *T,int N,char *what){
	int pos=0,neg=0;
	for (int i=0;i<N;++i){
		if(*(T+i)<0)	
			neg++;
		else 
			pos++;
	}	
	if(strcmp(what,"pos")==0)
		return pos;
	else if (strcmp(what,"neg")==0)
		return neg;
	else 
		puts("unown type deturmin pos or neg");
		exit(0);
}

//////

float *copy_table(float *T,int N,int N1,char *what){
	
	int i,j;
	float *T1=(float*)malloc(N1*sizeof(float));
	if(T==NULL){
		printf("memoire nom allouer\n");
		exit(0);
	}
	
	if(strcmp(what,"pos")==0){
		for (i=0,j=0;i<N;++i){
			if(*(T+i)>0){
				*(T1+j)=*(T+i);
				j++;
			}
		}
	}
	else if (strcmp(what,"neg")==0){
		for (i=0,j=0;i<N;i++){
			if(*(T+i)<0){
				*(T1+j)=*(T+i);
				j++;
			}
		}
	}
	return T1;
}


void comprer (int *T1,int N1,int *T2,int N2){
	int identique=1;
	if(N1!=N2){
		identique=0;
	}
	else{
		for(int i=0;i<N1;i++){
			if (T1[i]!=T2[i]){
				identique=0;
			}
		}

	}
	if(identique=0){
		printf("les tableau ne sont pas difirent\n");
	}
	else{printf("les tableau sont identique\n");}

}


int main (){

	int dim;
	float *T;
	char sign[3];
	printf("donne dimention N:");scanf("%d",&dim);
		
	T=saisire(T,dim);
	puts("tableau donner");
	affiche(T,dim);
	puts("done neg ou pos : ");scanf("%s",sign);
	//fgets(sign,3,stdin);
	//affiche(T,dim);
	int B=compte_nb(T,dim,sign);
	affiche(copy_table(T,dim,B,sign),B);
	
}
