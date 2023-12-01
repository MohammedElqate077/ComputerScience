#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main(int argc,char **argv){
	execlp("/bin/ls","ls","-R",argv[1],NULL);
}

