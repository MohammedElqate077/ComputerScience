#include<stdio.h>
#include<stdlib.h>


int main (){
	char repence;
	printf("doner r\t : ");repence=getchar();

	if (repence=='y' || repence=='Y')
		printf("  partie \n");
	else printf("ok 3la \n");
	return 0;
}
