#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(){
	FILE *F;

	F=fopen("sdfjskdfj","rb+");
	if(F){//!=NULL){ // if(!F) dont work is NULL;
		printf("test succes\n");

		fclose(F);
	}
	else
		printf("test falure\n");


	return 0;
}
