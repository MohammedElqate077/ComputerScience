#include<stdio.h>
int main()
{

printf("Welcome to DatafLair tutorials!\n\n");

printf("The current date is: %s\n", __DATE__ );
printf("The current time is: %s\n", __TIME__ );
printf("The total lines in the code is: %d\n", __LINE__ );
printf("The file name is: %s\n", __FILE__ );
printf("STDC would return the value: %d\n", __STDC__ ); // %d is used since it would return an integer value
return 0;
}
