#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<pthread.h>
#include<sys/stat.h>
#include<fcntl.h>

void waitexample()
{
	int i, stat;
	pid_t pid[5];
	for (i=0; i<5; i++)
	{
		if ((pid[i] = fork()) == 0)
		{
			sleep(1);
			exit(100 + i);
		}
	}

	// Using waitpid() and printing exit status
	// of children.
	for (i=0; i<5; i++)
	{
		pid_t cpid = waitpid(pid[i], &stat, 0);
		if (WIFEXITED(stat))
			printf("Child %d terminated with status: %d\n",
				cpid, WEXITSTATUS(stat));
	}
}

int main(){
	
	pid_t pid;
	int status=11;
	FILE *F;
	pid=fork();

	if(pid==-1){
		perror("faild proces creation\n");
			exit(errno);
	}
	
	else if(pid==0){
			F=fopen("useme","r");
			perror("Child_creation");
			fprintf(stderr,"Child_creation_err code %d:%s\n",errno,strerror(errno));
			exit(errno);
	}
	else{
		wait(&status);
			printf("parent_errno %d:%d\n\n",status,WEXITSTATUS(status));//strerror(status))	;
	//		F=fopen("useme","r");
	}
	
	for (int i=-1;i<10;i++){
		fprintf(stderr, "Error %d : %s\n",i, strerror( i ));
	//	perror("\terore code ");
	}

	//waitexample();
	return 0;
}

