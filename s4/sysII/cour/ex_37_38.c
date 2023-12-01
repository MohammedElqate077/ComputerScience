#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>


int main (){
	pid_t pid;
	pid=fork();
	
	switch (pid){
		case -1:
			printf("faild of creation proces\n");
			EXIT_FAILURE;//exit(1);
			break;
		case 0:
			printf("on est dans le le fils de PID %d et de PPID %d\n",getpid(),getppid());break;
		default: 
			sleep(5);
			printf("on est dans le pere de PID %d\n",getpid());break;
	}

	return 0;

}
