#include<stdio.h>

void affich(int *T,int nl,int nc);
void get_dim(int *L,int *C,int max);
int dimen(int nc,int ml);
void saisire(int *T,int nc,int nl);
void multiple(int *P,int *A,int *B,int nc,int nl,int mc,int max);
//void MULTI_2_MATRICES (int *MAT1, int *MAT2, int *MAT3,int N, int M, int P, int CMAX);
int main (){
  
   int A[50][50],B[50][50];
   int nl,nc,ml,mc;
   printf("**** MATRICE A (DIMENTION) ****\n");
   get_dim(&nl,&nc,50);
   printf("**** MATRICE B (DIMENTION) ****\n");
   get_dim(&ml,&mc,50);
   if(dimen(nc,ml)==0){
         printf("ne peut pas etre faire la multiplication\n");
         return 0;
      }
   else {
  // int P[nl][mc];
   int P[50][50];
   printf("**** DONNE MATRICE A ****\n");
   saisire((int *)A,nl,nc);
   printf("**** DONNE MATRICE B ****\n");
   saisire((int *)B,ml,mc);

 //  MULTI_2_MATRICES ((int *)P,(int *)A,(int *)B,nl,nc,mc,50);
   multiple((int *)P,(int *)A,(int *)B,nl,nc,mc,50);
   
   printf("**** MATRICE A ****\n");
   affich((int *)A,nl,nc);
   printf("**** MATRICE B ****\n");
   affich((int *)B,ml,mc);

   printf("**** MATRICE MULTIPLE (DIMENTION) ****\n");
   affich((int *)P,nl,mc);
   }
   return 0;
}

void get_dim(int *L,int *C,int max){
   do{
   printf("done nb de lignes et colone respectivment(max 50) \n");
   scanf("%d%d",L,C);
   }while ((*L>50 || *L<0) && (*C>50 || *C<0));
}
void saisire(int *T,int nc,int nl){
   int i,j;
   for (i=0;i<nl;i++)
      for (j=0;j<nc;j++){
         printf("element [%d][%d]=",i,j);
         scanf("%d",(T+i*nc+j));
      }
}
int dimen(int nc,int ml){
   if (nc==ml)
      return 1;
   else return 0;
}

void multiple(int *P,int *A,int *B,int nc,int nl,int mc,int max){
   int i,j,k,p;
   for(i=0;i<nl;i++){
      for (j=0;j<mc;j++){
         *(P+i*mc+j)=0;
         for (k=0;k<nl;k++)
             *(P+i*mc+j) += *(A+i*nl+k) * *(B+k*mc+j); 
      }  
   }
}

void affich(int *T,int nl,int nc){
int i,j;
   for(i=0;i<nl;i++){
      for(j=0;j<nc;j++){
         printf("%d ",*(T+i*nc+j));
      }
      printf("\n");
   }
}
