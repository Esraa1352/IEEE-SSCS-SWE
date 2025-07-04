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
- This gives the number of int elements between the addresses — not the number of bytes. (number of bytes/4)

---
## structs 
What if we want to group different types of entities (like animals, people, or objects), where each group has its own set of characteristics?" 
**How to use ?** 
`typedef struct`
`{`
 `char Name ;`
 `int ID ;`
`} name_of_struct; `
`name_of_struct member_of_struct={Esraa,202235};`

### Notes
- structs can be a return type of function `name_of_struct echo_data(void *data)` this returns a struct
- You can create pointers to structs  `name_of_struct *input ; ` this pointer can acess any element in this struct
**How to acess the elements?**
- we use the **->** operator 
- Example where DataType is a struct : `DataType d = {1, 2.5, 'x'};
  DataType *ptr = &d;
  printf("%d\n", ptr->i);   // prints 1`

  ## Memory Map

1- Data Segment
Stores global and static variables that are initialized.
`int a =5 `

2- BSS Segment
Stores global and static variables that are uninitialized or initialized to 0
`int a =0 ;
int m ;`

3-Stack Segment
Stores local variables (declared inside functions)

4- Heap Segment
Stores dynamically allocated memory using `malloc`, `calloc`, or `realloc`.

`malloc` **->** Allocates a block of memory of given size (in bytes) not initialized (garbage values)

`int *arr = (int*) malloc(5 * sizeof(int)); `

`calloc` **->** Allocates memory for an array of elements Initializes all bits to 0.

`int *arr = (int *) calloc (5 * sizeof(int));`

`realloc` Changes the size of previously allocated memory by `malloc` or `calloc`

`arr = (int*) realloc(arr, 10 * sizeof(int))`

**Important Note** we need to do a `free(arr);` after the allocations to free that held part  

5- Read-Only Data Segment
Stores string literals and constants.   
string literals **->** `char *str = "Hello";` 

⚠️**Remark** `char str[] = "Hello";` that is considered a local variable 

---
### memset
- a built in function in string.h library is used in C to set a block of memory with a particular value
`memset(pointer_to_block, value, size_in_bytes);`
----
### memcpy 
stands for memory copy. It is used to copy a block of memory from one location to another.
`memcpy(void *dest, const void *src, size_t num);`
where **size_t** is an unsigned integer type used to represent the size of objects in bytes.
