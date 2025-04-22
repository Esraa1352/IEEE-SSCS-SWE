#include <stdio.h>
#include "putchar.h"
int main (){
for (int i=0 ;i<=9 ;i++){
 for (int j=i+1 ;j<=9;j++){
     _putchar(i+'0');
     _putchar(j+'0');
     _putchar(',');}
}
return 0;

}
