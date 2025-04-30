#include <unistd.h> 
#include "putchar.h"
int _putchar(int fd ,char c)
{
	write(fd, &c, 1));
}
