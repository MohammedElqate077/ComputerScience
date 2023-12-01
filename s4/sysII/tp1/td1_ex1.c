#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
	
	pid_t fils;	
	int status=3492;	
	fils=fork();
	if(fils==-1){
		printf("error creation process");
		exit(-1);
	}
	else if(fils==0){
		printf("le fils de PID %d PPID %d\n",getpid(),getppid());
		exit(errno);
	}
	else{
		//sleep(20);
		//pid_t waitpid(fils,&status,NULL);
		//pid_t waitpid(fils,&status,NULL);
		wait(&status);
		printf("le pere de PID %d PPID %d\n",getpid(),getppid());
		printf("le code return %d  %d\n",status,WEXITSTATUS(status));
	}
}
