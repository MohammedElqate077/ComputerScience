#include <stdio.h>
struct numbers
{
   int num1, num2;
};
int main()
{
   // Assignment using using designated initialization
   struct numbers s1 = {.num2 = 22, .num1 = 11};
   struct numbers s2 = {.num2 = 30};
   
 
   printf ("s1 num1: %d, num2: %d\n", s1.num1, s1.num2);
   printf ("s2 num1: %d, num2: %d\n", s2.num1, s2.num2);
   s2=s1;
   printf ("s2 num1: %d, num2: %d\n", s2.num1, s2.num2);
   return 0;
}
