#include<stdio.h>
#include<stdlib.h>
#include<math.h>


typedef struct{
	float x;
	float y;
}Point;


typedef struct{
	Point A;
	Point B;
	Point C;
}Triengle;

void lire_pt(Point *pt){
	printf("donner x : ");scanf("%f",&pt->x);
	printf("donner y : ");scanf("%f",&pt->y);
}

float distence(Point U,Point V){
	double dis=sqrt((V.x-U.x)*(V.x-U.x)+(V.y-U.y)*(V.y-U.y));
	return dis;
}

void  air_triengle(Triengle tri){
	double air_tri;	
 	double temp=(tri.B.x-tri.A.x)*(tri.C.y-tri.A.y)*(tri.C.x-tri.A.y);
	if (temp<0) temp=-temp;
	air_tri=(1/2.0)*temp;
	printf(" air de triengle est %7.4lf \n",air_tri);
}
	
int main(){
	Triengle ABC;
	
	printf("\t\t #### entrer les info de triengle ####\n ");
	
	printf("\t info de pt A\n");
	lire_pt(&ABC.A);
	printf("\t info de pt B\n");
	lire_pt(&ABC.B);
	printf("\t info de pt C\n");
	lire_pt(&ABC.C);

	air_triengle(ABC);
}
