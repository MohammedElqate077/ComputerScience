#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
	int H,M,S;

	printf("\t\twhat is time now H:M:S !\n");
	printf("H:");scanf("%d",&H);
	printf("M:");scanf("%d",&M);
	printf("S:");scanf("%d",&S);

	if(H>24 || M>60 || S>60){
		printf("this clcok not define !");
	}
	else{
		while(1){
			printf("\n\n\t\t\t%02d:%02d:%02d",H,M,S);
			sleep(1);
			system("clear");
			S++;
			if(S>60){
				S=0;
				M++;
			}
			if(M>=60){
				M=0;
				H++;
			}	
			if(H>24){
				H=0;
				//M++;
			}
		}
	}
}
