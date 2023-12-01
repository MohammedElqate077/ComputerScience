#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
#include<fcntl.h>


int main(int argc,char **argv){
	int i,fd;
	char buf[10];
	fd=open("file.txt",O_CREAT|O_WRONLY,S_IRUSR|S_IWUSR);
	if(fd==-1){ perror("problem");exit(errno);}
	else{
		scanf("%s",buf);
		write(fd,buf,10);
		read(fd,buf,10);
		close(fd);
	}
}
