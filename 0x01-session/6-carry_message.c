#include<stdio.h>

void print_message(char *msg)
{
printf("message is : %s\n",msg);
}

int main()
{
char msg[]="hello world";
print_message(msg);
return 0;
}
