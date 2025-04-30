#include <stdio.h>

int sum_layers(int n)
{
  if(!n){
  return 0;
  }
  return n+sum_layers(n-1);
}

int main() 
{
int m=5;
printf("sum from %d to 1 is =%d",m,sum_layers(m));
return 0;
}
