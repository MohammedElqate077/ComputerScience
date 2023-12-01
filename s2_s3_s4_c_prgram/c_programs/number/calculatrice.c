#include<stdio.h>
#include<stdlib.h>
int main(){
	float x,y;
	char op;
	printf("enter les 2 nb et l'operateur\n");
	scanf("%f %f %c",&x,&y,&op);
	switch (op)
	{
	case '+' : printf(" + :%.2f\n",x+y);
	case '_' : printf(" - :%.2f\n",x-y);
	case '*' : printf(" * :%.2f\n",x*y);
	case '/' : 
				if (y=0 ){
					printf("divition inposible");}
				else{
					printf(" / :%.2f\n",x/y);}
	}

}
