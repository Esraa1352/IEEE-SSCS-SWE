### Functions And Intro To Pointers
**pointers:** simply a container saves the value in a certain address in the memory then saves this address in the container
so if we say 
`printf("%p",&ptr)` prints the address 
`printf("%d",ptr)` prints the value inside this address

**to declare a pointer --->**
- int/char/float/double *name_of_pointer
- int arr[5] ---> behaves like a pointer so if we say    
`printf("address of the first element of array is :%p",&arr)`
-int (*ptr array)[5] ---> points to the whole array
- int *p = NULL ---> Pointer that points to nothing
- 
