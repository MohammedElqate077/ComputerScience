#include<stdio.h>
#include<stdlib.h>
int i=0;
void persantage(double n);
int main(){
    double n;
    
    printf("entrer n=");scanf("%lf",&n);

    persantage(n);
}

void persantage(double n){
  
    for(i=0;i<=100;i++){
    	printf("per %d\t= %.2lf\n",i,(i*n)/100);
    } 
}
