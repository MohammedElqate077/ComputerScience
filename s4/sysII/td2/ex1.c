#include <stdio.h> 
#include <stdlib.h> 

int main(int argc, char **argv) { 
	int i, s; 
	s=0; 
	for (i=1; i<argc; i++) 
		s += atoi(argv[i]);
	printf("la somme est: %d\n", s); 
	return 0;
} 
