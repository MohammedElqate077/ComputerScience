#include<stdio.h>

 int main()
{
	float a,b ;
	for (a=0;a<10;a++){
		for(b=0;b<10;b++){
			if( (a-1)*2 == b+1)
				printf("%.0f,%.0f\t--> %.0f,%.0f \n",a,b,a-1,b+1);
		}

	}
}

