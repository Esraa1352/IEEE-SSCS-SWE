#include <stdio.h>
#include <stdarg.h>

void advanced_pretty_printer(const char flag, const char *separator, const unsigned int n,...)
{
    va_list args;
    va_start(args,n);
    for(int i=0 ; i < n ; i++ )
    {
        if (flag=='i')
        {
        printf("%d",va_arg(args,int));
        }
        if (flag=='s')
        {
            printf("%s",va_arg(args,char*));
        }
        if (i < n-1 )
        {
            printf("%s",separator);
        }
    }
    printf("\n");
    va_end(args);
}

int main ()
{
    advanced_pretty_printer('i',",",7,1,1,1,1,1,2,1);
    advanced_pretty_printer('s', " | ", 3, "HOla", "SOY", "DORA");

}