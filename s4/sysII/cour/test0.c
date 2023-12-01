#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
//for more tutorials on C, C++, STL, DS visit www.ProDeveloperTutorial.com

 
int main(int argc,char **argv) {
  pid_t pid;
  pid = fork();
  printf("\t * heloo  de PID %d et de PPID %d\n\n",getpid(),getppid());
  //printf("\n * helloo\n");
  if(pid == 0) 
  {
    printf("Child => PPID: %d PID: %d\n", getppid(), getpid());
    execvp("ls",argv);
    exit(EXIT_SUCCESS);
  } 
  else if(pid > 0) 
  {
    wait(NULL);
    printf("Child process finished.\n");
    printf("Parent => PID: %d\n", getpid());
  } 
  else 
  {
    printf("Unable to create child process.\n");
    perror("");
  }
 
  //printf("\n * helloo all\n\n");
  return EXIT_SUCCESS;
}
