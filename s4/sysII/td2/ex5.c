#include<stdio.h> 
#include<sys/types.h> 
#include<sys/stat.h> 
#include<fcntl.h> 
#include<unistd.h> 
#include<dirent.h> 
#define MAX_BUF 256 
int main(int argc, char **argv){ 
DIR *dirp; 
struct dirent *dp; 
char buf[MAX_BUF]; 
// Montrer le répertoire actuel 
getcwd(buf,MAX_BUF); 
printf("Répertoire actuel : %s\n",buf); 
// Ouvrir le répertoire passé comme argument 
dirp=opendir(argv[1]); 
// Lire entrée à entrée 
while((dp=readdir(dirp))!=NULL)
	printf("%s\n",dp->d_name); 
closedir(dirp); 
return 0;
} 
