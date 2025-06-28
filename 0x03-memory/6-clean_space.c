#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void *clear_allocation(size_t count, size_t size)
{
    void *arr= malloc(size * count);
    memset(arr, 0, count * size);
    return arr ;
}

int main ()
{
    size_t count=10;
    size_t size=sizeof (int);
    int *arr = (int *)clear_allocation(count, size);
    for (int i = 0; i < count; i++)
    {
        printf("%d ", arr[i]);  
    }

    free(arr); 
    return 0;
}
    
