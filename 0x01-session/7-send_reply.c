#include<stdio.h>

char *get_reply()
{
    return "reply recieved";
}
int main() {
char *reply =get_reply();
printf("%s\n",reply);
return 0;
}
