#include<stdio.h>

 int main()
{
	float x,y ;
	for (x=0;x<10;x++){
		for(y=0;y<10;y++){
			if( (x-1)*2 == y+1)
				printf("%.0f,%.0f\t-->\t%.0f,%.0f \n",x,y,x-1,y+1);
		}

	}
}

/*
 trouver couple x,y tq si en retranche 1 a x et on ajoute a y , le resulta final on trouve que y=2*x
*/
