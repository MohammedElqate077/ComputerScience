#include<stdio.h>

#define pi 3.14

int main()
{
	float d,p,s;
	const int R=20;
	//const float pi=3.14;
	d=2*R;
	p=pi*d;
	s=pi*R*R;
	printf("un cercle pour rayon %.2f,pour diametre %.2f,pour circonférence %.2f et pour surface %.2f\n",R,d,p,s);
	return 0;
}