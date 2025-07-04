# Functions And Intro To Pointers
### **pointers:** 
it is simply a container that saves the value in a certain address in the memory then saves this address in the container
so if we say 
- `printf("%p",ptr)` prints the address 
- `printf("%d",*ptr)` prints the value inside this address

**to declare a pointer --->**
- int/char/float/double *name_of_pointer
- int arr[5] ---> behaves like a pointer so if we say    
`printf("address of the first element of array is :%p",arr)` it prints thae address of the first element 
- int (*ptr array)[5] ---> points to the whole array
- int *p = NULL ---> Pointer that points to nothing
**Notes**
- %s expects a pointer to the first char of the string 
- when we say return "string" in functions it returns a pointer to the first char

---

### recursive functions
simply a function that loops around itself (calls itself) till a certain condition happens 
**how?** by simply calling the same function in it's body 
**Example:creating you own ATOI function**
**steps**
- Remember : it is a function that turns ASCII to Integer we previously mentioned that the main diffrence between then was that 5 means 5+'0' in ASCII
- first you'll need to determine the sign : make a counter that counts number of + and - and returns 1 if if + > - otherwise it returns -1
- then you'll need to extract each digit in the asci which is an array so str[i] where i the number of digits so we start by 0  `str[0]-'0'` returns it back the highest order number to being an integer
- `return result * 10 + (str[i] - '0');` to re arrange the numbers 
