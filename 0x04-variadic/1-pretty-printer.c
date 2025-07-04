#include <stdio.h>
#include <stdarg.h>

void pretty_printer(const char *separator, const unsigned int n, ...)
{
    va_list args;
    va_start(args,n);
    for(int i=0 ; i < n ; i++ )
    {
        printf("%d",va_arg(args,int));
        if (i < n-1 )
        {
            printf("%s",separator);
        }
    }
    va_end(args);
}

int main ()
{
    pretty_printer(",",7,1,1,1,1,1,2,1);
}