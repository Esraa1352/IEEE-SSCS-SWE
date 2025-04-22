#include<stdio.h>
#include"putchar.h"

int main()
{
int n;
printf("enter max number of times tables");
scanf(" %d",&n);
for (int i=0;i<=n;i++){
     for (int j=0;j<=9;j++){
     int m =i*j;
      if (m >=10){
       _putchar((m/10)+'0');
       _putchar((m%10)+'0');
       _putchar(',');
      }
     else{
     _putchar(m+'0');
    _putchar(',');
}

}
_putchar('\n');

}}



