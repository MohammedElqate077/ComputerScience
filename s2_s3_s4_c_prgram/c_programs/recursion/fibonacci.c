 
#include<stdio.h>
#include<stdlib.h>
 
int fibonacii(int n){   
    
    if(n==0 || n==1)
        return 1;
    else
        return fibonacii(n-1)+fibonacii(n-2);
    
}
int main(){
    int n;
     
    printf("enter le nombre: ");
    scanf("%d",&n);
     
    printf("fib(%d)=%d",n,fibonacii(n));

    printf("\n");   
    return 0;
}

/*     // pour affiche une serie de fibnocci a l'ordre n
void fibonacii(int a,int b, int n){   
    
    if(n>=0){
        printf("%d ",a+b);
        fibonacii(b,a+b,n-1);
    }
}

int main(){
    int a,b,n;

    a=1;        //premier term
    b=1;        //2 eme  term
     
    printf("Enter le total des nb de fibnocci: ");
    scanf("%d",&n);
     
    printf("serie de fibonacci est : ");

    printf("%d %d ",a,b);
    fibonacii(a,b,n-2);
    
    printf("\n");   
    return 0;
}
*/
