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

Primitive types (int, char, float, double):
- int - 2 or 4 bytes (1 byte is 8 bits)
- float - 4 bytes
- double - 8 bytes
- char - 1 byte

Basic format specifiers:
- `%d` or `%i` - int
- `%f` or `%F` - float
- `%lf` - double
- `%c` - char
- `%s` - used for strings (text)

```c
// store multiple characters in a variable
char myText[] = "Hello";
printf("%s", myText);
```

> [!tip] *float* vs *double* - The precision of a floating point value indicates how many digits the value can have after the decimal point. The precision of *float* is six or seven decimal digits, while *double* variables have a precision of about 15 digits. Therefore, it is often safer to use *double* for most calculations - but note that it takes pup twice as much memory as *float* (8 bytes vs 4 bytes)

- scientific numbers - you can write very large numbers or very small floating-point numbers using scientific numbers. The syntax is:
```c
float f1 = 35e3; // 35 * 10^3 = 35_000
double d1 = 12E4; // 12 * 10^4 = 120_000;

// e or E means times 10 to the power of

printf("%f", f1);
printf("%lf", d1);
```

- decimal precision
```c
float myFloatNum = 3.5;

printf("%f", myFloatNum); //default shows 6 digits after the decimal point
printf("%.1f", myFloatNum); // only 1 digit
printf("%.2f", myFloatNum); // only 2 digits
printf("%.4f", myFloatNum); // only 4 digits
```

sizeof operator
- unsigned interger variable size check
```c
int myInt;

printf("%zu", sizeof(myInt)); // %zu is the format specifier for size_t which is the type of unsigned integer
```

signed vs unsigned
- more data types

| type | size | range | format specifier |
| --------------- | --------------- | --------------- | --------------- |
| short int | 2 bytes  | -32_768 to 32_767 | %hd |
| unsigned int | 2 or 4 bytes  | 0 - 65_535 (2bytes) or  0 - 4_294_967_295 (4 bytes) | %u |
| long int | 4 or 8 bytes  | -2,147,483,648 to 2,147,483,647 (4 bytes) -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 (8 bytes) | %ld |
| long long int | 8 bytes  | -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 | %lld |
| unsigned long int | 4 or 8 bytes  | 0 to 4,294,967,295 (4 bytes) or 0 to 18,446,744,073,709,551,615 (8 bytes) | %lu |
| unsigned long long int | 8 bytes  | 0 to 18,446,744,073,709,551,615 | %llu |
| long double | 8, 12 or 16 bytes  | Implementation-dependent, but more precision than double | %Lf |

> [!tip] *unsigned* means the type can only store non-negative values (0 and up).
> These extended types are mostly used when you need very specific control over memory usage or number ranges.
> For everyday programming, `int, float, double, char` are usually enough.

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
