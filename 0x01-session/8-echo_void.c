#include<stdio.h>

void echo(int n)
{
    if (!n){
    return ;}
    printf("%d:echo\n",n);
    echo (n-1) ;
}

int main()
{
echo (13);
}
