#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>
#include<sys/types.h>
#include<sys/wait.h>


	//pthread_t pt1;

void* fnct1(void* arg)
{
	char ch='*';
//	printf("thread1 pid %d de PPID %d\n",getpid(),getppid());
	for(int i=0;i<1000;++i){
	//	printf("*");
		write(1,&ch,1);
	}
//	printf("\n");
	//pthread_exit(NULL);
	//return NULL;
}
void* fnct2(void* arg){

	//pthread_join(pt1,NULL);
	char ch='#';
//	printf("thread2 pid %d de PPID %d\n",getpid(),getppid());
	for(int i=0;i<1000;++i){
		//printf("*");
		write(1,&ch,1);
	}
//	printf("\n");
	//pthread_exit(NULL);
	//return NULL;
}
int main()
{
	pthread_t pt1;
	pthread_t pt2;

	int i=20;
	pthread_create(&pt1, NULL,fnct1,NULL);
	pthread_create(&pt2, NULL,fnct2,NULL);
	pthread_join(pt1,NULL);
	pthread_join(pt2,NULL);
	printf("parent pid %d de PPID %d\n",getpid(),getppid());
	i+=100;

	printf("parent i %d\n",i);

	return 0;
}

