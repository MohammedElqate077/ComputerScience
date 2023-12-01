#include<iostream>

using namespace std; 

int main(){
	int entier=1293;
	float reel=123.83;
	char caractre='B';
	string chaine="we test that";
	char chaine1[]="good is true";
	double reeel[5]={2,43,23.432,23,912} ;

	cout << entier << endl;
	cout << reel << endl;
	cout << caractre << endl;
	cout << chaine << endl; 
	cout << chaine1 <<endl;
	

	cout << "affichage tableaur reel" << endl;
	for(int i=0;i<5;i++)
		cout << reeel[i] << " >> ";
	
	cout <<	"\n \t \t ** USR DONNER ** " << endl;
	cin >> entier >> reel >> caractre >> chaine;
	cout << entier << endl;
	cout << reel << endl;
	cout << caractre << endl;
	cout << chaine << endl; 
	
	return 0;
}
