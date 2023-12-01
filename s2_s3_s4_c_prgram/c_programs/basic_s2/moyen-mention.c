#include <stdio.h>
int main(){
	float n1,n2,n3,c1,c2,c3,moy;
	printf("enter les 3 notes (n1,n2,n3)\n");
	scanf("%f %f %f",&n1,&n2,&n3);
	printf("enter les 3 coeficions (c1 ,c2 ,c3)\n");
	scanf("%f%f%f",&c1,&c2,&c3);
	moy=(n1*c1+n2+c2+n3*c3)/3;

        if(moy<10) 
            printf("moyen faible\n");
        else if(moy<12) 
            printf("moyen passable\n"); 
        else if(moy<14)
            printf("moyen A.bien\n");
        else if(moy<16) 
            printf("moyen bien\n");
        else if(moy<18) 
            printf("moyen T.bien\n");
        else if(moy<=20) 
            printf("moyen excellent\n");
        /*
	if(moy<10)
		printf("moyen faible\n");
	
	else
		if(moy<12)
			printf("moyen passable\n");
		else
			if(moy<14)
				printf("moyen A.bien\n");
			
			else
				if(moy<16)
				printf("moyen bien\n");
				
				else
					if(moy<18)
						printf("moyen T.bien\n");
					
					else
						if(moy<=20)
							printf("moyen excellent\n");
                                                        */
}
/*
#include <stdio.h>
int main(){
	float n1,n2,n3,c1,c2,c3,moy;
	printf("enter les 3 notes (n1,n2,n3)\n");
	scanf("%f %f %f",&n1,&n2,&n3);
	printf("enter les 3 coeficions (c1 ,c2 ,c3)\n");
	scanf("%f%f%f",&c1,&c2,&c3);
	moy=(n1*c1+n2+c2+n3*c3)/3;
	if(moy<10){
		printf("moyen faible\n");
	}
	else{
		if(moy<12){
			printf("moyen passable\n");
		}
		else{
			if(moy<14){
				printf("moyen A.bien\n");
			}
			else{
				if(moy<16){
				printf("moyen bien\n");
				}
				else{ 
					if(moy<18){
						printf("moyen T.bien\n");
					}
					else{
						if(moy<=20){
							printf("moyen excellent\n");
						}
					}
				}
			}
		}
	}
}
*/



