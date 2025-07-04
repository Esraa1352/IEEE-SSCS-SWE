# Variadic Function 
A variadic function is a function that can take a variable number of arguments.
### What is New to know so we can use it ?
- declare the function as func(int n ,...)
  
- `va_list args` This declares a variable args of type va_list.
it will be used to access the additional arguments passed after the named parameters.

👉 Think of it like a pointer or cursor that can step through the unnamed arguments one by one. 


- `va_start` va_start(args, last_named_parameter);
This initializes the args list so you can start reading from it.
🔍 last_named_parameter is the last fixed argument before the ... 
It tells va_start where the variable arguments begin  



- `va_arg(args, type);` This retrieves the next argument in the list and advances the pointer.
**For example** `va_arg(args, int)` gets the next argument of type int.



- `va_end(args);` This cleans up after you've finished using the va_list.

👉 It’s important to call va_end before exiting the function to avoid undefined behavior.

