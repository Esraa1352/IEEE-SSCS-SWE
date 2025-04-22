#include <stdio.h>
#include "putchar.h"

int main(void)
{
    for (char c = 'a'; c <= 'z'; c++){ 
        if (c!='q')
        _putchar(c);  
         }
     for (char c='z';c>='a';c--){
          if (c!='q')
         _putchar(c-32);}


    return 0;
}

