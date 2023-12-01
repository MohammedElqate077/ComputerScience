#include<string.h>
#include"pile.h"
void reverse(char s[])
 {
     int i, j;
     char c;

     for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
         c = s[i];
         s[i] = s[j];
         s[j] = c;
     }
}

void itoa(int n, char s[])
 {
     int i, sign;

     if ((sign = n) < 0)  /* record sign */
         n = -n;          /* make n positive */
     i = 0;
     do {       /* generate digits in reverse order */
         s[i++] = n % 10 + '0';   /* get next digit */
     } while ((n /= 10) > 0);     /* delete it */
     if (sign < 0)
         s[i++] = '-';
     s[i] = '\0';
    reverse(s);
} 

int est_oper(char C){
	if (C!='+' || C!='-' || C!='*' || C!='/')
			return 0;
	return 1;
}

int calcule(char *a,char *b,char op){
	if(op=='+') return atoi(a)+atoi(b);
	if(op=='-') return atoi(a)-atoi(b);
	if(op=='*') return atoi(a)*atoi(b);
	if(op=='/') return atoi(a)/atoi(b);
	if(op=='%') return atoi(a)%atoi(b);
}
/*
char *trans(char *ch){
	Pile *P=create_pile();
	int j=0;
	while(j<strlen(ch)){
		if()			
		if(ch[i])			
		
	}
}
*/

int polonaise(char *ch){
	int i;	
	//int a,b;
	int res;
	char *now=(char*)malloc(sizeof(char));
	Pile *P=create_pile();

	//for(i=0;i<strlen(ch);i++){
	for(i=0;i<7;i++){
		if(est_oper(ch[i])){
			//a=atoi(dipiler_pile(P));
			//b=atoi(dipiler_pile(P));
			res=calcule(dipiler_pile(P),dipiler_pile(P),ch[i]);
			//itoa(res,now,10);// is not on linux library he (sai) in not secure on the buffer;
			itoa(res,now);
			empile_pile(P,now);

		}
		else{
			empile_pile(P,&ch[i]);
		}
	}
	return res;
}



int main(){	
	Pile *P;
	char ch[7];
	printf("entre la chaine\n");
	gets(ch);
	printf("res %d\n",polonaise(ch));
	return 0;
}
