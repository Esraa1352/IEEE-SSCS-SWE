#include <stdio.h>

void status(int n)
{
    if (n > 0)
        printf("Positive\n");
    else if (n < 0)
        printf("Negative\n");
    else
        printf("Zero\n");
}

int main()
{
    void (*ptr)(int) = status;  // Function pointer assignment
    ptr(10);
    ptr(0);
    ptr(-5);
    return 0;
}

