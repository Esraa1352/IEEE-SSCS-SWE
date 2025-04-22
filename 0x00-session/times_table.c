#include<stdio.h>
#include"putchar.h"

int main()
{
for (int i=0;i<=9;i++){
     for (int j=0;j<=9;j++){
     int m =i*j;
      if (m >=10){
       _putchar((m/10)+'0');
       _putchar((m%10)+'0');
      _putchar(',');}
     else{
     _putchar(m+'0');
     _putchar(',');}

}
_putchar('\n');
}}

