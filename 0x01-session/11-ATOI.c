#include "putchar.h"
#include <fcntl.h>
#include <unistd.h>
#include "ATOI.h"

int convert(const char *strg) {
int i = 0;
int result = 0;
int p_count = 0;
int n_count = 0;
int sign;

int fd = open("converted_numbers.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
if (fd == -1) {
return 0;
}

// Determine the sign first
for (i = 0; strg[i] == '-' || strg[i] == '+'; i++) {
if (strg[i] == '-') n_count++;
if (strg[i] == '+') p_count++;
}
if (p_count >= n_count)
{
sign =1;
}
else 
{
sign=-1;
}

// Convert numeric part
while (strg[i] >= '0' && strg[i] <= '9')
{
result = result * 10 + (strg[i] - '0');
i++;
}

result *= sign;

// Output result using _putchar
if (result < 0)
{
_putchar(fd, '-');
result = -result;
}

if (result == 0) {
_putchar(fd, '0');
}
else
{
char buffer[10];
int j = 0;
while (result > 0) {
buffer[j++] = (result % 10) + '0';
result /= 10;
}
for (int k = j - 1; k >= 0; k--) {
_putchar(fd, buffer[k]);
}
}

_putchar(fd, '\n');
close(fd);

return result * ((sign == -1) ? -1 : 1);
}

