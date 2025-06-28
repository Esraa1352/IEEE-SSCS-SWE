#include <stdlib.h>
#include <stdio.h>

int *summon_allies(int *allies, int n)
{
    int *arr = (int *)malloc(sizeof(int) * n);
    if (arr == NULL)
    {
        printf("Allocation failed.\n");
        return NULL;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    return arr;
}

int main()
{
    int n = 0;
    printf("Enter number of elements in your array: ");
    scanf("%d", &n);

    int *filled_array = NULL;
    filled_array = summon_allies(filled_array, n);


    printf("Your allies are: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", filled_array[i]);
    }
    printf("\n");

    free(filled_array); // Don't forget to free allocated memory
    return 0;
}
