#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// saisire le tableau
int *saisire(int *T,int taille){
	for (int i=0;i<taille;i++){
		printf("entrer element num %d : ",i+1);
		scanf("%d",T+i);}
	return T;
}

//alouer le memoire pour le tabeau
int *allouer(int taille){
	int *T=(int *)malloc(taille*sizeof(int));
	if(T==NULL){
		printf("memoire nom allouer\n");
		exit(0);}
	else printf("memoire allouer avec succes\n");
	return T;
}

//affiche le tableau
void affiche(int *T,int taille){
	printf("T[%d]=",taille);
	for (int i=0;i<taille;++i)
		printf(" %d ",*(T+i));
	printf("\n");
}

//realouer le tableau
int *reallouer(int *T,int taille){
	int *Temp=(int *)realloc(T,taille*sizeof(int));
	if(Temp==NULL){
		printf("memoire nom allouer\n");
		exit(0);}
	else printf("memoire allouer avec succes\n");
	return Temp;
}

//inser element
void inservaleurs(int *T,int *taille,int ind,int n){
	int i;
	int k;
	if(ind>*taille||ind<0){
		printf("bad indice\t aucun element a insere");
	}
	else{
		for(k=1;k<=n;k++){
			if(k%2!=0){
				*taille+=1;
				T=reallouer(T, *taille);
				for(i=*taille-1;i>ind-1;i--){
					*(T+i+1)=*(T+i);
				}
				*(T+ind)=k;
				ind++;
			}
		}
	} 
}

//suprimer element
int suprimer_double(int *T,int *taille){
	int i,j,k;//compt1=0;
	int newsize=taille;
	for (i=0;i<newsize-1;i++)
	{
		for(j=i+1;j<newsize;j++){
			if(T[i]==T[j]){
				for(k=j;k<newsize;k++){
					T[k]=T[k+1];
					}
					newsize--;
					j--;
				}
		}
	}
	//*taille=(*taille)-compt1;
	T=reallouer(T,newsize);
	return newsize;
}
/*
 
int suprimer_double(int *T,int newsize){
	int i,j,k;//compt1=0;
	for (i=0;i<newsize;i++)
	{
		for(j=i+1;j<newsize;j++)
		{
    		if(T[i]==T[j])
    		{
    			for(k=j;k<newsize;k++)
    			{
    				T[k]=T[k+1];
				}
				newsize--;
				j--;
			}
		}
	}
	*taille=(*taille)-compt1;
	T=reallouer(T,newsize);
	return newsize;
}
*/
void echange(int *x,int *y){
	int temp=*x;
	*x=*y;
	*y=temp;
}

void tri_bule(int *T,int taille){
	int repass;
	int j;
	int i=taille-1;
	do{
		repass=0;
		j=0;
		while(j<=i-1){
			if(T[j]>T[j+1]){
				echange(&T[j],&T[j+1]);
				repass=1;
			}
			j++;
		}
		i--;
	}while(repass || i>=1);

}

void compare_tableau(int *T1,int N1,int *T2,int N2){
	int i,identique=1;
	for (int i=0,j=0;i<N1,j<N2;++i,++j){
		if (T1[i]!=T2[j])
			identique=0;break;
	}
	if(identique==0) printf("tableau diferent !=\n");
	else printf("tableau identique ==\n");
}

int main (){

	int dim,ind,val;
	int *T;
	printf("donne dimention taille:");scanf("%d",&dim);
	T=saisire(allouer(dim),dim);
	puts("tableau donner");
	affiche(T,dim);
	printf("donne indice et la valeur (respesctivement):");scanf("%d%d",&ind,&val);
	inservaleurs(T,&dim,ind,val);
	puts("eleminer les doublon et les multiple");
	tri_bule(T,dim);
	dim=suprimer_double(T,dim);
	//fgets(sign,3,stdin);
	puts("tableau resultat");
	affiche(T,dim);
	
}

