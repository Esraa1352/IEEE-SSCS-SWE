#include <stdio.h>
#include "putchar.h"
int main (){
for (int i=0 ;i<=7 ;i++){
  for (int j=i+1 ;j<=8;j++){
    for(int m=j+1 ;m<=9 ;m++){ 
     _putchar(i+'0');
     _putchar(j+'0');
     _putchar(m+'0'); 
     _putchar(',');
}}}
return 0;
}

