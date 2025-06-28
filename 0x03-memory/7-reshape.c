#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void *_reshape(void *ptr, size_t old_size, size_t new_size)
{
  
    if (ptr == NULL)
    {
        return malloc(new_size);
    }

    
    if (new_size == 0)
    {
        free(ptr);
        return NULL;
    }

    
    if (new_size <= old_size)
    {
        void *new_ptr = malloc(new_size);
        if (new_ptr == NULL) return NULL;
        memcpy(new_ptr, ptr, new_size);
        free(ptr);
        return new_ptr;
    }

   
    if (new_size > old_size)
    {
        void *new_ptr = malloc(new_size);
        if (new_ptr == NULL) return NULL;
        memcpy(new_ptr, ptr, old_size);
        free(ptr);
        return new_ptr;
    }

 
    return NULL;
}
int main()
    {
        int *arr = malloc(3 * sizeof(int));
        if (arr == NULL) return 1;
        arr[0] = 1;
        arr[1] = 3;
        arr[2] = 2;
    
        size_t old_size = 3 * sizeof(int);
        size_t new_size = 5 * sizeof(int);  
        arr = _reshape(arr, old_size, new_size);

        for (int i = 0; i < 5; i++)
        {
            printf("%d ", arr[i]);
        }
        free(arr);
    
        return 0;
    }