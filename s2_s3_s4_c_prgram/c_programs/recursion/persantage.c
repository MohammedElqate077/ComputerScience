#include<stdio.h>
#include<stdlib.h>
int i=0;
double persantage(double n,int i);
int main(){
    double n;
    
    printf("entrer n=");scanf("%lf",&n);

    persantage(n,0);
}

double persantage(double n,int i){
  
  //double var;
    if (i==101){
      
        return 1;
    }
   
    
    printf("per %d\t= %.2lf\n",i,(i*n)/100);
//    i++;
    return persantage(n,++i);// not i++
    
}
