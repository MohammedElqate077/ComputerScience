#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
#include<fcntl.h>


int main(int argc,char **argv){
	int fd;

	fd=open("file.txt",O_CREAT|O_RDWR,S_IRUSR|S_IWUSR);
	if(fd==-1){
		perror("problem");
		return errno;
	}
	if((lseek(fd,10,SEEK_SET))<0){
		perror("problem");
		return errno;
	}
	if(write(fd,"main_ni",7)<0)
		return errno;

	return 0;

}
