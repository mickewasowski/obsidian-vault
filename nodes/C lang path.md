---
aliases:
context:
---

# C lang path

---

C Language - Basics - Data Types - Pointers - Arrays - Structs - Memory Allocation - Strings - Function Pointers

1. ## C LANGUAGE (for DSA + Systems)

> 1.1. C Basics

Compilation (gcc - compiler, clang)
Structure of a C program
Header files, include guards
main function, return codes

> [!tip] The main difference between C and C++ is that C++ supports classes and objects, while C does not.
> C ignores white space but we use it to make the code more readable.
> Every C statement ends with a semicolon ;
> When you are working with text it must be wrapped in double quotes ""
> `printf` does not insert a new line. To add a new line add `\n` (escape sequence) to your string.

- commments - `//` for single line comments (everything after them will be ignored), `/**/` multiline in between the asterics will be ignored
- declaring variables:
```c
    type variableName = value;
    
    int myNum = 15;

    // declare variable without assigning a value
    int test;

    // assign a value later
    test = 21;
```
- printing variable values - *format specifiers*
```c
// a format specifier is used with printf, it is a placeholder for the type of data
// it starts with % and followed by a character

// int -> %d
// char -> %c
// float -> %f

int myNum = 15;
char myLetter = 'D';

printf("My number is %d and my letter is %c.", myNum, myLetter);
```

- changing values
```c
int test = 15;

test = 20;

int copy = test;

int test2;

test2 = copy;
```
- declare multiple variables in one line
```c
int x = 5, y = 6, z = 50;
printf("%d", x, y, z);

// assign the same value to multiple variables in one line
int x, y, z;

x = y = z = 50;
```
- variable names must begin with a letter or an underscore, cannot contain whitespaces or special characters



> 1.2. Data Types & Memory Layout

Primitive types (int, char, float, double)
signed vs unsigned
sizeof operator
stack vs heap memory
endianness (optional, useful later)


> 1.3. Pointers

pointer declaration (int \*p)
referencing vs dereferencing (&, \*)
pointer arithmetic
pointers to arrays
pointers to pointers
void pointers


> 1.4. Arrays

static arrays
dynamic arrays
iteration
array decay to pointer


> 1.5. Strings

null-terminators
C-string functions (strlen, strcpy, strcmp…)
buffer overflows (very important)


> 1.6. Dynamic Memory

malloc, calloc, realloc, free
memory leaks
segmentation faults
creating resizable structures


> 1.7. Structs

defining structs
pointers to structs
accessing fields with . vs ->
representing nodes in data structures


> 1.8. Function Concepts

pass-by-value
passing pointers to modify data
function pointers (optional but useful)


> 1.9. File I/O (optional for now)

fopen
fread/fwrite
fclose
