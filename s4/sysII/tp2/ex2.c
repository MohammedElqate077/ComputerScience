#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

struct persone{
	char nom[20];
	char prenon[20];
	char tel[11];
};


int main(int argc,char *argv[]){
	int fd;
	
	struct persone p;
	//fd=open("fiche",O_CREAT|O_WRONLY);
	fd=open("fiche",O_CREAT|O_RDWR,S_IRUSR|S_IWUSR);
	/*if (fd=-1){
		return 1;
	}*/
	int i=0;	
	while(i<3){
		printf("\t info persones %d\n",i+1);
		printf("    nom :");scanf(" %s",p.nom);//fgets(fi->nom,15,stdin);
    		printf("    prenon :");scanf(" %s",p.prenon);//fgets(fi->prenon,15,stdin);	
    		printf("    telephone :");scanf(" %s",p.tel);//fgets(fi->prenon,15,stdin);	
		write(fd,&p,sizeof(p));
		i++;
	}
	int ret=lseek(fd,0,SEEK_SET);
	i=0;
	while(i<4){
		read(fd,&p,sizeof(p));
		printf("\t affichage des infos persones %d\n",i+1);
		printf("    nom : %s \t\t\t",p.nom);
    		printf("    prenon : %s\t\t\t",p.prenon);
    		printf("    telephone : %s\n",p.tel);
		i++;

	}
	close(fd);
	return 0;
}
