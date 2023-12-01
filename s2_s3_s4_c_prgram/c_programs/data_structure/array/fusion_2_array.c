#include<stdio.h>

void saisire(int T[],int dim);
void fusion(int *A,int *B,int *Fus,int N,int M);
void affich(int T[],int dim);

int main (){
	int N,M,j;
	
	printf("entrer dimention de 1er tableau : ");scanf("%d",&N);
	printf("entrer dimention de 2eme tableau : ");scanf("%d",&M);
	
//	int Y=N+M;
	int A[N],B[M],Fus[N+M];

	
	printf("donne 1er tableau \n");saisire(A,N);
	printf("donne de 2eme tableau \n");saisire(B,M);
	
	fusion(A,B,Fus,N,M);//,N+M);	

	printf("1er tableau  ");affich(A,N);
	printf("2eme tableau  ");affich(B,M);

	printf("tableau fusioner ");affich(Fus,N+M);
}

void saisire(int T[],int dim){
	for (int i=0;i<dim;i++){
		printf("element %d : ",i+1);
		scanf("%d",&T[i]);
	}
	printf("\n");
}

void fusion(int *A,int *B,int *Fus,int N,int M){//,int Y){
	int ifus=0,ia=0,ib=0;
	while( (ia<N) && (ib<M) ){
		if (A[ia]<B[ib]){
			Fus[ifus]=A[ia];
			ifus++;
			ia++;
		}
		else{
			Fus[ifus]=B[ib];
			ifus++;
			ib++;
		}
	}
	while(ia<N){
		Fus[ifus]=A[ia];
		ifus++;
		ia++;
	}		
	while(ib<M){
		Fus[ifus]=B[ib];
		ifus++;
		ib++;
	}		
}

void affich(int T[],int dim){
//	for (int i=0;i<dim;i++){
//		printf("%d ",T[i]);
//	}
	while (dim){
	printf("%d ",*T);
	T++;
	dim--;
	}
	printf("\n");
}


