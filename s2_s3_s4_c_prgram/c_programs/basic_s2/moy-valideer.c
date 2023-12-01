#include<stdio.h>
int main(){
	int n1,n2,n3;
	//int some;
	float moy;
	printf("entrer les 3 notes\n");
	scanf("%d%d%d",&n1,&n2,&n3);
	//some=n1+n2+n3;
	moy=(n1+n2+n3)/3.0;
	if (moy>=10) 
		printf("moyen est %.2f ==> module valider\n",moy);
	else
		if(moy<5)
			printf("moyen est %.2f ==> note ileminatoire\n",moy);
		else printf("moyen est %.2f ==> ratrappage\n",moy);
}