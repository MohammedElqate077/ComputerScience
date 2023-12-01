#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/wait.h>


int main() {
	pid_t pid;
	int x = 1;
	//pid = fork();
	pid = 0;
	pid = fork();
	if (pid == 0) { 
		printf("Dans fils : x=%d\n", ++x); 
		pid = fork();
	//	exit(0);
	}else
 		printf("Dans père : x=%d\n", --x);
	return 0;
}
