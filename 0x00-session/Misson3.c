#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main(void)
{
    int n, last_digit;

    srand(time(0));
    n = rand() - RAND_MAX / 2;

     if (n % 2 == 0) {
        printf("n = %d which is even\n", n);
    } else {
        printf("n = %d which is odd\n", n);
    }

    last_digit = abs(n) % 10;


    printf("The last digit is %d and it is ", last_digit);

    if (last_digit > 5) {
        printf("more than 5.\n");
    } else {
        printf("less than or equal to 5.\n");
    }

    return 0;
}


