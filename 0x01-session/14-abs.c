#include <stdio.h>
#include "putchar.h"
#include "ATOI.h"

int my_abs(int x)
{
if (x < 0)
{
x=-x;
}
return x;
}


int convert(const char * , char *argv[])

int main(int argc, char *argv[]) {
int sum = 0;


for (int i = 1; i < argc; i++) {
int num = convert(argv[i]);
sum += my_abs(num);  // Sum of absolute values
}

char buffer[20];
int i = 0;

if (sum == 0) {
buffer[i++] = '0';
} else {
int temp = sum;
while (temp > 0) {
buffer[i++] = (temp % 10) + '0';
temp /= 10;
}
}

write(1, "Sum of absolute values: ", 25);
for (int j = i - 1; j >= 0; j--) {
write(1, &buffer[j], 1);
}
write(1, "\n", 1);

return 0;
}

