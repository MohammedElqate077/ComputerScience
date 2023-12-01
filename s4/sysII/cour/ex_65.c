#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>

// pour compiler il faut ajoute l'option gcc -lpthread  == gcc -lpthread file.c -o file

void* func(void* i)
{
	//i=(int *)i;
	//int j=*(int*)i+10;
	*(int*)i+=100;
	printf("thread pid %d de PPID %d\n",getpid(),getppid());
	printf("thread i %d\n",*(int*)i);
	
//	printf("thread i %d\n",*i);
	//while(1); infinite loop;
	pthread_exit(NULL);
	return NULL;
}

int main()
{
	pthread_t tid;
	int i=20;
	//pthread_create(&tid, NULL,func,&i);
	pthread_create(&tid, NULL,(void*)func,&i);
	pthread_join(tid,NULL);
	printf("parent pid %d de PPID %d\n",getpid(),getppid());
	i+=100;

	printf("parent i %d\n",i);

	return 0;
}


