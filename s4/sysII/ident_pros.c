#include <stdio.h>
#include<stdlib.h>
#include <unistd.h>
int main(void)
{
printf("Processus %d , de père %d , taille d’un pid = %ld octets \n", getpid(),getppid(),sizeof(pid_t));
return 0;
}
