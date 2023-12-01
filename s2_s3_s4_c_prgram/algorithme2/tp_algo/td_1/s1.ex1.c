// programe nombre arabe to roman
#include<stdio.h>
#include<stdlib.h>

int foncI (char *rom,int i){
		if(rom[i+1]=='V') return 4;
		if(rom[i+1]=='X') return 9;	
		return 1;
}

int foncX (char *rom,int i){
		if(rom[i+1]=='L') return 40;
		if(rom[i+1]=='C') return 90;	
		return 10;
}

int foncC (char *rom,int i){
		if(rom[i+1]=='D') return 400;
		if(rom[i+1]=='M') return 900;
		return 100;
}

int romcon (char *rom){
	int i=0,r,n=0;
	while(rom[i]!='\0'){
		switch(rom[i]){
			case 'I':
				r=foncI(rom,i);
				if(r!=1){
					i++;
				}
				n+=r;
				break;
			case 'V':
				n+=5;
				break;
			case 'X':
				r=foncX(rom,i);
				if(r!=10){
					i++;
				}
				n+=r;
				break;
			case 'L':
				n+=50;
				break;
			case 'C':
				r=foncC(rom,i);
				if(r!=100){
					i++;
				}
				n+=r;
				break;
			case 'D':
				n+=500;
				break;
			case 'M':
				n+=1000;
				break;
			default:
				printf("ERROR NOT ROMAN NUMBER\n");
				return 0;
		}
		i++;
	}
	return n;
}

int main()
{
	int n=0;
	char rom[100];
	printf("Romane number = ");scanf("%s",rom);
	printf("%s = %d\n",rom,romcon(rom));
	return 0 ;
}


/*

#include<stdio.h>
#include<stdlib.h>


int fonc (char *rom,int i, char c){
	if (c == 'I') {
		if(rom[i+1]=='V') return 4;
		else if(rom[i+1]=='X') return 9;	
		else return 1;
	}
	else if (c=='X'){
		if(rom[i+1]=='L') return 40;
		else if(rom[i+1]=='C') return 90;	
		else return 10;
	}
	else if(c=='C'){
		if(rom[i+1]=='D') return 400;
		else if(rom[i+1]=='M') return 900;
		else return 100;
	}
}






int romcon (char *rom){
	int i=0,r,n=0;
			
	while(rom[i]!='\0'){
		switch(rom[i]){

			case 'I':
				r=fonc(rom,i,'I');
				if(r!=1){
					i++;
				}
				n+=r;

				break;

			case 'V':
				n+=5;
				break;

			case 'X':
				r=fonc(rom,i,'X');
				if(r!=10){
					i++;
				}
				n+=r;
				break;

			case 'L':
				n+=50;
				break;

			case 'C':
				r=fonc(rom,i,'C');
				if(r!=100){
					i++;
				}
				n+=r;
				break;

			case 'D':
				n+=500;

				break;

			case 'M':
				n+=1000;
				break;

		}
		i++;

	}

	return n;


}


*/

/*
#include<stdio.h>
#include<string.h>

int ROM2AR(char R[]);
int cara_I(char R[],int i);
int cara_X(char R[],int i);
int cara_C(char R[],int i);

int main()
{
	char R[1000];int A;
	printf("entrer le chifre romanie : ");
	scanf("%s",R);
	A=ROM2AR(R);
	printf("%d\n",A);
}

int ROM2AR (char R[]){
	int i,r,N=0;			
	for(i=0;i<strlen(R);i++)
	{
		switch(R[i])
		{
			case 'I':
				r=cara_I(R,i);
				if(r!=1){
					i++;
				}
				N+=r; break;

			case 'V':
				N+=5; break;

			case 'X':
				r=cara_X(R,i);
				if(r!=10)
				{
					i++;
				}
				N+=r; break;

			case 'L':
				N+=50;
				break;

			case 'C':
				r=cara_C(R,i);
				if(r!=100)
				{
					i++;
				}
				N+=r; break;

			case 'D':
				N+=500; break;

			case 'M':
				N+=1000; break;
		}
	}
	return N;
}

int cara_I(char R[],int i){
		if(R[i+1]=='V'){ 
			return 4;
		}
		if(R[i+1]=='X'){
			return 9;	
		}
		else{
			return 1;
		}
}

int cara_X(char R[],int i){	
		if(R[i+1]=='L') {
			return 40;
		}
		if(R[i+1]=='C'){
			return 90;	
		}
		else{
			return 10;
		}
}

int cara_C(char R[],int i){	
		if(R[i+1]=='D'){
			return 400;
		}
		if(R[i+1]=='M'){ 
			return 900;
		}
		else {
			return 100;
		}
}

*/
