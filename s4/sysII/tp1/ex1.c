#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(void){
        int i;
        for (i=0;i<=9;i++){
                if(fork()==0){
        		for (i=0;i<=9;i++)
                       		printf("%d",i);
                }
	}
       // printf("\n");
        return 0;
}


