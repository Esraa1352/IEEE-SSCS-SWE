#include<stdio.h>


int sumDigits (long long int n)
{
int sum ,digits;
if (n==0)
{
return 0;
}
digits=n%10;
sum=digits+sumDigits(n / 10);
}

int main()
{
long long int m =123456789;
sumDigits (m);
printf("sum of digits is =%d\n",sumDigits (m));
return 0;
}
