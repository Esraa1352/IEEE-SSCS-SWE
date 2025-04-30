#include <stdio.h>

void swap(int *a, int *b)
{
int temp =*b;
*b=*a;
*a=temp ;
}
int main()
{
int m=13 , n=5 ;
printf("values before swap are : m=%d ,n=%d\n ",m,n);
swap(&m, &n);
printf("After swapping: m = %d, n = %d\n\n", m, n);
return 0;
}
