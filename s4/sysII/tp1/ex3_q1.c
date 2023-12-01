#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>


int main (){
	int i;
	pid_t pid;
	pid=fork();
	char c;
	if(pid==-1)
		perror("fork_problem");
	else if (pid==0){
		c='*';
		for(i=0;i<200;++i)
		//	printf("*");
			write(1,&c,1);
			
	}
	else{
		wait(NULL);
		c='#';
		for(i=0;i<200;++i)
		//	printf("#");
			write(1,&c,1);
	}
	//printf("\n");
	return 0;
}
