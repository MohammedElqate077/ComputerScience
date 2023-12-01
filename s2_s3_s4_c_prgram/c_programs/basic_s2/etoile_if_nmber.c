#include<stdio.h>
#include<stdlib.h>


int main(){
	char c;

	while((c=getchar())!=EOF){
		if(c>='0' && c<='9')
			putchar('*');
		else 
			putchar(c);
	}
	
}
