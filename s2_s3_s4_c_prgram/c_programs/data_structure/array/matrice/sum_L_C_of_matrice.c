#include <stdio.h>

int main(){
	int t[50][50];
    int l,c,i,j,s;
    printf("Nombre de lignes   (max.50) : ");scanf("%d",&l);
    printf("Nombre de colonnes (max.50) : ");scanf("%d",&c);
    for(i=0;i<l;i++){
    	for(j=0;j<c;j++){
        	printf("Element[%d][%d] : ",i,j);
            scanf("%d",&t[i][j]);
     	}
	}
    printf("Tableau donné :\n");
    for(i=0;i<l;i++){
    	for(j=0;j<c;j++){
        	printf("%7d",t[i][j]);
 		}
    	printf("\n");
    }
    for(i=0;i<l;i++){
    	for(s=0,j=0;j<c;j++){
        	s+=t[i][j];
		}
        printf("Somme des lignes %d : %ld\n",i,s);
	}
 	for(j=0;j<c;j++){
		for(s=0,i=0;i<l;i++){
			s+=t[i][j];
		}
		printf("Somme des colonnes %d : %ld\n",j,s);
    }
    return 0;
  }
