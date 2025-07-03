### First Task Note

## C 

### Mission 0: Why compiler?
**1-C (Compiled language):** Imagine as a strict boss who reviews your work thoroughly before you get paid. If there’s any mistake, no matter how small, the boss refuses to give you your salary and won’t let you proceed. Similarly, C compiles your entire code first—checking for errors—and only if everything is perfect does it run the program. If the compilation fails, the program won’t run at all.
**2-PYTHON(Interpreted Language):** On the other hand, Python is like a boss who lets you start working immediately and checks your work as you go along. It interprets your code line by line, so you can run the program even if there are mistakes in parts you haven’t reached yet. Errors only show up when the problematic line is executed otherwise before that error every thing runs and executes smoothly, which makes it flexible


---
### Mission 1:
**ASCI CODE**
Computers and compilers don’t understand letters the way we do , they communicate in numbers. Think of ASCII as a Google Translate between human-readable characters and computer language. For example, when you send the character 'A', it’s translated to the number 65, which is its ASCII code.
so to print out integers in characters form we don't just do in ASCI language it is 
`int B = 5 ;
printf ("%c",B+'0');`


---
### Mission 2:
**Common Mistake**
assigning a value to a variable is done through `int m = 2 `
but checking if the variable is of a certain value is done through `if m == 2`


 ---
## Mission 3:
**Put Char**
we are creating our new limited printf function it prints a character per time 
in order to use it in multiple files to print we need too make a header so we don't need to write the function each time 
**BUT How?**

**_putchar.h**

1-create a file with the name _putchar.h
2-we need to know first about guard 
- #ifndef extra step we take to prevent errors caused by accidentally including the same header file multiple times.
- #define creates a macro or a symbol. 
**you might be wondering What the hell is a marco?"** 
- macro in C (and many other languages with preprocessors) is basically a rule or shorthand that tells the compiler to replace some text with something else before actual compilation starts.
**Suggestion: just know the simple concepts and know that you need to write**
3- now comes the easy part which is just defining the function `chat _putchar(char c)`

**_putchar.c**

1- create a file with the name _putchar.c
2- remember what we did with define and indef ? it helps us to just write `#include _putchar.h` whenever we want to use _putchar function so write that 
3- here comes what our function does so
**how do we print without using print ?**
1- we include another library Contains declarations for many low-level system calls, such as:
write() → for output which is `#include unistd.h`
2- we need to know how to use Write() we pass to this function 3 things 
- 1 which is standard output (stdout)  
-&c address of the character
-number of bytes to be printed 'in this case 1 as we print 1 character '

**to use this in any code we simply**
`#include _putchar.h 
_putchar('H');
return 0;`

---

### Tasks
 

