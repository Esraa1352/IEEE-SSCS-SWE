#include <stdio.h>
#include <stdlib.h>

int global_variable = 10; // data segment

int main()
{
    int local_variable = 20; // stack
    int *heap_variable = (int *)malloc(sizeof(int)); // heap
    char *string_literal = "IEEE"; // read only data segment 

    *heap_variable = 30;

    printf("address %p : data segment   -> %d\n", &global_variable, global_variable);
    printf("address %p : stack segment  -> %d\n", &local_variable, local_variable);
    printf("address %p : heap segment   -> %d\n", heap_variable, *heap_variable);
    printf("address %p : read only data segment -> %s\n", string_literal, string_literal); //%s excepects a pointer of the first element of string 

    free(heap_variable);

    return 0;
}
