#include <stdio.h>


 
int print(int i) {
  printf("print function %d\n",i);

 }

int main(void) {
  int a = 20;
 
  /* here 'b == -5' is not evaluated,
     since a 'a != 20' is false. */
  if (a != 20 && printf(a)) {
    printf("I won't be printed!\n");
  }
  if (a == 20 && printf(a)) {
    printf("I be printed!\n");
  }
   
  return 0;
}
