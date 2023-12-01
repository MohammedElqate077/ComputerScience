#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main (int argc,char **argv){
	int menu;
	printf("1 pour vim:\n");
	printf("2 pour affiche:\n");
	printf("3 pour suprimer:\n");
	scanf("%d",&menu);
	switch(menu){
		case 1: execlp("vim","vim",argv[1],NULL);break;
		case 2: execlp("cat","cat",argv[1],NULL);break;
		case 3: execlp("rm","rm","-i",argv[1],NULL);break;
		default : 
			printf("error d\'enter\n");
			exit(0);
	}
	return 0; 

}
