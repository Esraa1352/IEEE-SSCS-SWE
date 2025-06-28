#include"putchar.h"
#include <fcntl.h>

{
int i=0;
int result=0;
int p_count=0;
int n_count=0;
int sign=0;
//detrmine sign first
for (i=0;strg[i] == '-' || strg[i] == '+' ;i++ )
{
if (strg[i] == '-')
{
n_count++;
}
if (strg[i] == '+')
{
p_count=++;
}}
if (p_count>n_count){
sign=1;
}
else {
sign=-1;
}
while(strg[i]!='\0'){
result=result*10+(strg[i]-'0');
i++;
}
result=result*sign;
return result;
}
