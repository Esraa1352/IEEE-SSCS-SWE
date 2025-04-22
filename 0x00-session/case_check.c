#include <stdio.h>
#include <ctype.h>
int main() {
char c;
printf("Enter a character: ");
    scanf("%c", &c);
  if (isupper(c)) {
        printf("The character '%c' is uppercase.\n", c);
    } else if (islower(c)) {
        printf("The character '%c' is lowercase.\n", c);
    } 

    return 0;
}

