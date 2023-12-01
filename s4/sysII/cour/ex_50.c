#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/wait.h>

extern char **environ;

int main(){
	
	for (int i=0;i<20 && environ+i!=NULL;i++){
		printf("%s\n",*(environ+i));

	}
	//uid_t one;
	printf("user id %d\n",getuid());
	return EXIT_SUCCESS;
}
