# More Pointers and Struct

## How to Create a function pointer?
- **declare the pointer** ` return_type (*pointer_name)(parameter_types);`    
- **assaign the pointer to the function**  `func_ptr = function ;
- we can call the function through the pointer `func_ptr(5)`
---
## Notes From Tasks
### manual_sizeof function**
`char *start=(char* ) &arr[0];`
`char *end  =(char*)  &arr[1];`
`int size=end-start;`

**why casting to char ?**
- `int* ptr; ptr + 1` moves forward by 4 bytes  the size of an int.
-`char* ptr; ptr + 1` moves forward by 1 byte the size of a char.
So subtracting `int *start, *end; ` `end - start`

 This gives the number of int elements between the addresses — not the number of bytes. (number of bytes/4)
 
