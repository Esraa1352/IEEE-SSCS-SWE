#include<stdio.h>

int main()
{
int signal = 98;
int *ptr =&signal;
printf("address=%p\n",ptr);
printf("value=%d",*ptr);
return 0;
}
