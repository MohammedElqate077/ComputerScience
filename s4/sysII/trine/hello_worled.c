#include<stdio.h>
#include<sys/types.h>
int main() {
	fork();
     	printf("Hello_World\n");
	fork();
//	if(fork() || fork())
     		printf("Hello_World\n");
     	//sleep(1000);                      //provide some wait

	return 0;
}
