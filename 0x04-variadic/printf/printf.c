/* =========================================================
 *                        _printf.c
 * ========================================================= */
#include "printf.h"
#include <stdarg.h>
#include <stddef.h>

/* ---------- 1) for width & left/right padding ---------- */
static void print_padded(const char *s, int len,
                         int width, int left, int *count)
{
    int pad = (width > len) ? width - len : 0;

    if (!left)                 /* right aligned (default) */
        for (int p = 0; p < pad; p++) { _putchar(' '); (*count)++; }

    for (int j = 0; j < len; j++)  { _putchar(s[j]); (*count)++; }

    if ( left)                 /* left aligned with %- */
        for (int p = 0; p < pad; p++) { _putchar(' '); (*count)++; }
}

/* =========================================================
 *                         _printf
 * ========================================================= */
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
            /* ---------- 2) parse flags / width  ---------- */
            i++;                       /* skip '%' */
            while (format[i] == ' ')     i++;          /* skip spaces flag */

            int plus_flag  = 0;
            int left_align = 0;
            int width      = 0;

            if (format[i] == '+') { plus_flag = 1; i++; }
            if (format[i] == '-') { left_align = 1; i++; }

            while (format[i] >= '0' && format[i] <= '9')
            {
                width = width * 10 + (format[i] - '0');
                i++;
            }

            /* ---------- 3) SPECIFIER BLOCKS ---------- */

            /* -- CHAR -- */
            if (format[i] == 'c')
            {
                char c = (char)va_arg(args, int);
                print_padded(&c, 1, width, left_align, &count);
            }

            /* -- SIGNED DECIMAL (%d) -- */
            else if (format[i] == 'd')
            {
                int num = va_arg(args, int);
                char arr[12];  int m = 0;

                if (num < 0)
                {
                    arr[m++] = '-';
                    num = -num;
                }
                else if (plus_flag)
                    arr[m++] = '+';

                /* build digits in reverse order */
                if (num == 0) arr[m++] = '0';
                else
                {
                    while (num > 0)
                    {
                        arr[m++] = (num % 10) + '0';
                        num /= 10;
                    }
                }

                /* reverse to print in correct order */
                for (int j = (arr[0] == '-' || arr[0] == '+') ? 1 : 0,
                         k = m - 1; j < k; j++, k--)
                {
                    char tmp = arr[j]; arr[j] = arr[k]; arr[k] = tmp;
                }
                print_padded(arr, m, width, left_align, &count);
            }

            /* -- STRING (%s) -- */
            else if (format[i] == 's')
            {
                char *string = va_arg(args, char *);
                if (string == NULL) string = "(null)";

                int len = 0; while (string[len]) len++;
                print_padded(string, len, width, left_align, &count);
            }

            /* -- LITERAL PERCENT (%%) -- */
            else if (format[i] == '%')
            {
                _putchar('%'); count++;
            }

            /* -- BINARY (%b) -- */
            else if (format[i] == 'b')
            {
                int num = va_arg(args, int);
                char binary[32]; int j = 0;

                if (num == 0) binary[j++] = '0';
                else
                {
                    if (num < 0) { _putchar('-'); count++; num = -num; }
                    while (num > 0)
                    {
                        binary[j++] = (num % 2) + '0';
                        num /= 2;
                    }
                }

                for (int k = j - 1; k >= 0; k--) { _putchar(binary[k]); count++; }
            }

            /* -- OCTAL (%o) -- */
            else if (format[i] == 'o')
            {
                int num = va_arg(args, int);
                char octal[12]; int j = 0;

                if (num == 0) octal[j++] = '0';
                else
                {
                    if (num < 0) { _putchar('-'); count++; num = -num; }
                    while (num > 0)
                    {
                        octal[j++] = (num % 8) + '0';
                        num /= 8;
                    }
                }

                for (int k = j - 1; k >= 0; k--) { _putchar(octal[k]); count++; }
            }

            /* -- HEXADECIMAL lowercase (%h) -- */
            else if (format[i] == 'h')
            {
                int num = va_arg(args, int);
                char hexa[12]; int j = 0;

                if (num == 0) hexa[j++] = '0';
                else
                {
                    if (num < 0) { _putchar('-'); count++; num = -num; }
                    while (num > 0)
                    {
                        int d = num % 16;
                        hexa[j++] = (d < 10) ? d + '0' : d - 10 + 'a';
                        num /= 16;
                    }
                }

                for (int k = j - 1; k >= 0; k--) { _putchar(hexa[k]); count++; }
            }

            /* -- HEXADECIMAL UPPERCASE (%X) --*/
            else if (format[i] == 'X')
            {
                int num = va_arg(args, int);
                char hexa[12]; int j = 0;

                if (num == 0) hexa[j++] = '0';
                else
                {
                    if (num < 0) { _putchar('-'); count++; num = -num; }
                    while (num > 0)
                    {
                        int d = num % 16;
                        hexa[j++] = (d < 10) ? d + '0' : d - 10 + 'A';
                        num /= 16;
                    }
                }

                for (int k = j - 1; k >= 0; k--) { _putchar(hexa[k]); count++; }
            }

            /* -- UNSIGNED DECIMAL (%u) -- */
            else if (format[i] == 'u')
            {
                unsigned int num = va_arg(args, unsigned int);
                char arr[12]; int m = 0;

                if (num == 0) arr[m++] = '0';
                else
                {
                    while (num > 0)
                    {
                        arr[m++] = (num % 10) + '0';
                        num /= 10;
                    }
                }

                for (int j = m - 1; j >= 0; j--) { _putchar(arr[j]); count++; }
            }

            /* -- POINTER (%p) --*****/
            else if (format[i] == 'p')
            {
                void *ptr = va_arg(args, void *);
                unsigned long addr = (unsigned long) ptr;

                _putchar('0'); _putchar('x'); count += 2;

                if (addr == 0)
                {
                    _putchar('0'); count++;
                }
                else
                {
                    char hex[16]; int j = 0;

                    while (addr > 0)
                    {
                        int d = addr % 16;
                        hex[j++] = (d < 10) ? d + '0' : d - 10 + 'a';
                        addr /= 16;
                    }
                    for (int k = j - 1; k >= 0; k--) { _putchar(hex[k]); count++; }
                }
            }

            /* -- LOWERCASE STRING (%_s) --*/
            else if (format[i] == '_' && format[i + 1] == 's')
            {
                i++;                 /* step so we'll land on 's' at end */
                char *str = va_arg(args, char *);
                if (!str) str = "(null)";

                char tmp[1024]; int n = 0;
                while (str[n]) { tmp[n] = my_tolower(str[n]); n++; }
                tmp[n] = '\0';
                print_padded(tmp, n, width, left_align, &count);
            }

            /* -- UPPERCASE STRING (%=s) --*/
            else if (format[i] == '=' && format[i + 1] == 's')
            {
                i++;                 /* step so we'll land on 's' at end */
                char *str = va_arg(args, char *);
                if (!str) str = "(null)";

                char tmp[1024]; int n = 0;
                while (str[n]) { tmp[n] = my_toupper(str[n]); n++; }
                tmp[n] = '\0';
                print_padded(tmp, n, width, left_align, &count);
            }

            /* -- REVERSE STRING (%r) -- */
            else if (format[i] == 'r')
            {
                char *str = va_arg(args, char *);
                if (!str) str = "(null)";

                int len = 0; while (str[len]) len++;

                for (int k = len - 1; k >= 0; k--) { _putchar(str[k]); count++; }
            }

            /* -- UNKNOWN: treat as literal -- */
            else
            {
                _putchar('%');
                _putchar(format[i]);
                count += 2;
            }

            i++;      /* advance past current specifier char */
        }
        else
        {
            _putchar(format[i]);
            i++;
            count++;
        }
    }

    va_end(args);
    return count;
}

int main()
{
    int printed = 0;
    int x = 1234;
    void *ptr = &x;

    // Basic types
    printed = _printf("1. Char: %c\n", 'A');
    _printf("   → printed = %d\n\n", printed);

    printed = _printf("2. String: %s\n", "Hello World");
    _printf("   → printed = %d\n\n", printed);

    printed = _printf("3. Signed decimal (%%d): %d\n", -42);
    _printf("   → printed = %d\n\n", printed);

    printed = _printf("4. Unsigned (%%u): %u\n", 4294967295U);
    _printf("   → printed = %d\n\n", printed);

    // Flags
    printed = _printf("5. Plus flag: %+d %+d\n", 42, -42);
    _printf("   → printed = %d\n\n", printed);

    printed = _printf("6. Left aligned: %-5d done\n", 7);
    _printf("   → printed = %d\n\n", printed);

    printed = _printf("7. Right aligned: %5d done\n", 7);
    _printf("   → printed = %d\n\n", printed);

    // Binary, octal, hex
    printed = _printf("8. Binary (%%b): %b\n", 13);
    _printf("   → printed = %d\n\n", printed);

    printed = _printf("9. Octal (%%o): %o\n", 50);
    _printf("   → printed = %d\n\n", printed);

    printed = _printf("10. Hex lowercase (%%h): %h\n", 20);
    _printf("    → printed = %d\n\n", printed);

    printed = _printf("11. Hex uppercase (%%X): %X\n", 20);
    _printf("    → printed = %d\n\n", printed);

    // Pointer
    printed = _printf("12. Pointer (%%p): %p\n", ptr);
    _printf("    → printed = %d\n\n", printed);

    // Special string conversions
    printed = _printf("13. Lowercase string (%%_s): %_s\n", "alo");
    _printf("    → printed = %d\n\n", printed);

    printed = _printf("14. Uppercase string (%%=s): %=s\n", "alo");
    _printf("    → printed = %d\n\n", printed);

    // Reverse
    printed = _printf("15. Reverse (%%r): %r\n", "abcde");
    _printf("    → printed = %d\n\n", printed);

    // Null string
    printed = _printf("16. NULL string: %s %_s %=s %r\n", NULL, NULL);
    _printf("    → printed = %d\n\n", printed);

    // Unknown specifier
    printed = _printf("17. Unknown: %q\n");
    _printf("    → printed = %d\n\n", printed);

    // Literal percent
    printed = _printf("18. Percent sign (%%): %%\n");
    _printf("    → printed = %d\n\n", printed);

    return 0;
}

