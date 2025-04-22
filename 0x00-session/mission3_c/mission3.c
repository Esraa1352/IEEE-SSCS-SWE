#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main(void)
{
    int n;
    int m;

    srand(time(0));
    n = rand() - RAND_MAX / 2;
    m = n % 10;

    printf("Number is %d\n", n);
    printf("The last digit is %d, it is ", last_digit);

    if (last_digit % 2 == 0)
        printf("even");
    else
        printf("odd");

    if (last_digit > 5)
        printf(" and greater than 5.\n");
    else if (last_digit < 5)
        printf(" and less than 5.\n");
    else
        printf(" and equal to 5.\n");

    return 0;
}
