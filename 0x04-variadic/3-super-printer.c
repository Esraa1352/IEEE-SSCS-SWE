#include <stdio.h>
#include <stdarg.h>

void super_printer(const char *flag, ...)
{
    va_list args;
    va_start(args, flag);

    int first = 1; 

    for (int i = 0; flag[i] != '\0'; i++) 
    {
        if (flag[i] != 'i' && flag[i] != 's' && flag[i] != 'f' && flag[i] != 'c')
            continue;

        if (!first)
            printf(", ");
        else
            first = 0;

        if (flag[i] == 'i')
        {
            printf("%d", va_arg(args, int));
        }
        else if (flag[i] == 's')
        {
            char *str = va_arg(args, char *);
            printf("%s", str ? str : "(nil)");
        }
        else if (flag[i] == 'f')
        {
            printf("%f", va_arg(args, double)); 
        }
        else if (flag[i] == 'c')
        {
            printf("%c", va_arg(args, int));
        }
    }

    printf("\n");
    va_end(args);
}

int main(void)
{
    super_printer("ii", 7, 1); 
    super_printer("sss", "HOla", "SOY", "DORA"); 
    super_printer("cfi", 'X', 3.14, 42); 
    super_printer("s", NULL); 
    return 0;
}
