#include <stdio.h>

// Recursively count digits
int countDigits(long long int n) {
    if (n < 0)
        n = -n;
    if (n < 10)
        return 1;
    return 1 + countDigits(n / 10);
}

// Recursively sum digits
int sumDigits(long long int n) {
    if (n < 0)
        n = -n;
    if (n == 0)
        return 0;
    return (n % 10) + sumDigits(n / 10);
}

int main() {
    long long int m = -123456789;  // Trying 
    int sum = sumDigits(m);
    int count = countDigits(m);

    printf("Sum of digits is = %d\n", sum);
    printf("Number of digits is = %d\n", count);

    return 0;
}

