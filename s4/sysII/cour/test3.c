#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argc,char **argv){
		
	printf("argc %d\n\n",argc);
	for(int i=0;i<argc;i++)
		printf("arg_%d %s\n",i,argv[i]);

	system("ls");
	printf("\n\n");
	//execl("/bin/ls","ls",argv[1],argv[2],NULL);//argv[1],argv[2],NULL);
	//execlp("ls",argv[1],argv[2],argv[3],NULL);//argv[1],argv[2],NULL);
	//execlp("ls",argv[0],argv[1],argv[2],argv[3],NULL);//argv[1],argv[2],NULL);
	//execlp("ls","ls",NULL);//argv[1],argv[2],NULL);
	//execl("/bin/ls",argv[2],argv[3],NULL);
	//execv("/bin/ls",argv);
	//execvp("ps",argv);


	//printf("%s le pid %d ppid %d \n",argv[0],getpid(),getppid());
	
	//execvp("argv[0]",argv);
	//perror("same thing hapning");

	return 0;
}

