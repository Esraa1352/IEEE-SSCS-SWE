#include "printf.h"
#include <stdarg.h>
#include <stddef.h>

int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;

    if (format == NULL)
        return -1;

    va_start(args, format);

    while (format[i] != '\0')
    {
        if (format[i] == '%' && format[i + 1] != '\0')
        {
            i++; 
            if (format[i] == 'c')
            {
                _putchar(va_arg(args, int));
                count++;
            }
            else if (format[i] == 'd')
            {
                int num = va_arg(args, int);
                
                if (num < 0)
                {
                    _putchar('-');
                    num = -num;
                    count++;
                }
                else 
                {
                    _putchar('+');   
                    count++;
                }
            
                if (num == 0)
                {
                    _putchar('0');
                    count++;
                }
                else
                {
                    char arr[10];  
                    int m = 0;
            
                    while (num > 0)
                    {
                        arr[m++] = (num % 10) + '0'; 
                        num = num / 10;
                    }
            
                    for (int j = m - 1; j >= 0; j--)
                    {
                        _putchar(arr[j]);
                        count++;
                    }
                }
            }

            else if (format[i] == 's')
            {
                char *string = va_arg(args, char *);
                if (string == NULL)
                    string = "(null)";  
                for (int j = 0; string[j] != '\0'; j++)
                {
                    _putchar(string[j]);
                    count++;
                }
            }
            else if (format[i] == '%')
            {
                _putchar('%');
                count++;
            }
            else if (format[i] == 'b')
            {
                int num = va_arg(args, int);
                
                if (num == 0)
                {
                    _putchar('0');
                    count++;
                }
                else
                {
                    char binary[32]; 
                    int j = 0;

                    if (num < 0)
                    {
                        _putchar('-');
                        num = -num;
                        count++;
                    }

                    while (num > 0)
                    {
                        binary[j++] = (num % 2) + '0';
                        num = num / 2;
                    }

                    for (int k = j - 1; k >= 0; k--)
                    {
                        _putchar(binary[k]);
                        count++;
                    }
                }
            }
                else if (format[i] == 'o')
                {
                    int num = va_arg(args, int);
                    
                    if (num == 0)
                    {
                        _putchar('0');
                        count++;
                    }
                    else
                    {
                        char octal[8]; 
                        int j = 0;
    
                        if (num < 0)
                        {
                            _putchar('-');
                            num = -num;
                            count++;
                        }
    
                        while (num > 0)
                        {
                            octal[j++] = (num % 8) + '0';
                            num = num / 8;
                        }
    
                        for (int k = j - 1; k >= 0; k--)
                        {
                            _putchar(octal[k]);
                            count++;
                        }
                    }
                }
                else if (format[i] == 'h')
                {
                    int num = va_arg(args, int);
                
                    if (num == 0)
                    {
                        _putchar('0');
                        count++;
                    }
                    else
                    {
                        char hexa[10];
                        int j = 0;
                
                        if (num < 0)
                        {
                            _putchar('-');
                            num = -num;
                            count++;
                        }
                
                        while (num > 0)
                        {
                            int digit = num % 16;
                            if (digit < 10)
                                hexa[j++] = digit + '0';
                            else
                                hexa[j++] = digit - 10 + 'a'; 
                            num = num / 16;
                        }
                
                        for (int k = j - 1; k >= 0; k--)
                        {
                            _putchar(hexa[k]);
                            count++;
                        }
                    }
                }
                
                else if (format[i] == 'u')
                {
                    unsigned int num = va_arg(args, unsigned int);

                        if (num == 0)
                        {
                            _putchar('0');
                            count++;
                        }
                        else
                        {
                        char arr[10];  
                        int m = 0;

                        while (num > 0)
                        {
                            arr[m++] = (num % 10) + '0'; 
                            num = num / 10;
                        }

                        for (int j = m - 1; j >= 0; j--)
                        {
                            _putchar(arr[j]);
                            count++;
                        }
                    }
                }


            else
            {
                _putchar('%');
                _putchar(format[i]);
                count += 2;
            }
        }
        else
        {
            _putchar(format[i]);
            count++;
        }
        i++;
    }

    va_end(args);
    return count; 
}
int main(void)
{
    int count=0;

    count=  _printf("characters test: %c\n",'A');
    count = _printf("integers test: %d\n", 123);
    count = _printf("String test: %s\n", "alooo");
    count = _printf("Percent sign test: %%\n");
    count = _printf("NULL string test: %s\n", (char *)NULL);
    count = _printf("Unknown specifier test: %q\n");
    count = _printf("Binary conversion test: %b\n" , 123);
    count = _printf("Octal conversion test: %o\n" , 123);
    count = _printf("unsigned integer test: %u\n" , -1);
    count = _printf("hexadecimal conversion test: %h\n" , 123);

    _printf("number of printed characters test: %d\n", count);

    return 0;
}