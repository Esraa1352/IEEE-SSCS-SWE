#include <unistd.h>  //to use write

void my_putstr(int fd, const char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    write(fd, str, len);// or i can use strlen(str) and include #include <string.h>
}


