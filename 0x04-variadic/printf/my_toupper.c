#include "printf.h"

char my_toupper(char c)
{
    return (c >= 'a' && c <= 'z') ? c - 32 : c;
}