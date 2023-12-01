#include<stdio.h>
#include<stdlib.h>
double power(double x,int n){
	double p=1;

	if(n>0){
		while (n>0){
			p*=x;
			n--;
		}
	}
	else {
		n*=-1;
		while(n>0){
			p*=1/x;
		n--;
		}
	}
	return p;
}

int main(){
    int n;
    double x;
    printf("entrer respictivement x et n\n");scanf("%lf%d",&x,&n);
    printf("%.2lf\n",power(x,n));
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

