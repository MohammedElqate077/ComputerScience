#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void saisire_fiche_c(char *P){
	char C;
	FILE *F=fopen(P,"w");
	if (F==NULL){
		printf("oops !! faild opening file or creation of text.txt\n");
		exit(1);
	}
	printf("\t * * saisire dans le fichier\n");
	do{
		C=getchar();
		fputc(C,F);
	}while(C!=EOF);
	fclose(F);
	//int ch; while ((ch=getchar())!='\n' && ch!=EOF){continue;}//for cleaning the bufer input
	return;
}

void lire_file_c(char *P){
	FILE *F=fopen(P,"r");
	char C;
	if (F==NULL){
		printf("oops !! faild opening file \n");
		exit(1);
	}
	while((C=fgetc(F))!=EOF){
		putchar(C);
	}
	fclose(F);
	return;

}

int main (){
	FILE *F=fopen("text.text","a");
	char PATH [1000];
	char ch;
	if (F==NULL){
		printf("oops !! faild opening file\n");
		exit(1);
	}
	else{
		saisire_fiche_c("text.txt");
		stdin=freopen(NULL,"r",stdin);//save your time and effictive cleaning the bufer without any eror(work fine on linux)
		printf("\n \t \t * entre the path of file you want affiche her :)\n");
		fflush(stdin);
		scanf("%s",PATH);
		lire_file_c(PATH);
		remove("/home/mylinux/myhome/my_projects/projects/c-programs/s4/pro2/2019_2020/tp3/text2.txt");
	}
}
