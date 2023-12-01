#include<iostream>
#include<cstring>
#include<string>
using namespace std;


int romcon(char *R);int foncI (char *rom,int i);
int foncX (char *rom,int i);
int foncC (char *rom,int i);


int main(){
	char rom[100];
	char n=0;
	cout << "entrer romane number\n";
	cin >> rom;
	cout << romcon(rom) << endl;

	//string now="MOhammedElqate"; now.append
	
}

int romcon(char *R){
	int i=0,n=0,r;
	while(R[i]!='\0'){
		switch(R[i]){
			case 'I' :
				if((r=foncI(R,i))!=1) i++; break;
			case 'V' :
				r=5;break;
			case 'X' :
				if((r=foncI(R,i))!=10) i++; break;
			case 'L' :
				r=50;break;
			case 'C' :
				if((r=foncI(R,i))!=100) i++; break;
			case 'D' :
				r=500;break;
			case 'M' :
				r=1000;break;
		}
		i++;
		n+=r;
	}
	return n;
}


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
