#include<stdio.h>
#include<stdlib.h>
double power(double p,double x,int n){
    if(n==0)
        return p;
  
    else{
       // p*=x;
        return power(p*x,x,n-1);}
}

int main(){
    int n;
    double x,p=1;
    printf("entrer respictivement x et n\n");scanf("%lf%d",&x,&n);
    printf("%.2lf\n",power(p,x,n));
}



/*
#include<stdio.h>
#include<stdlib.h>
double power(double x,int n){
   
    if(n==0)
        return 1;
 
    else{
        
        return x*power(x,n-1);}
}

int main(){
    int n;
    double x;
    printf("entrer respictivement x et n\n");scanf("%lf%d",&x,&n);
    printf("%.2lf\n",power(x,n));
}
*/

