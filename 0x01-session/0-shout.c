#include <stdio.h>

void repeat_message(int n)
{
for (int i=1;i<=n;i++)
{
printf("%d: hello world \n",i);
}
}
int main ()
{
  repeat_message(5); //for trying the code 
    return 0;
}

