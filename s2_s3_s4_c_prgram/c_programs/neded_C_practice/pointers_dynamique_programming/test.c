#include <stdio.h>

int main(){
	const int q = 5;
	//Compilation error
	int *const p = &q;

	//Valid
	*p = 7;

	const int q2 = 7;

	//Compilation error
//	p = &q2;

	printf("is %d",*p);
	return 0;
}

