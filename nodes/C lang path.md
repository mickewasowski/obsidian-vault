---
aliases:
context:
---

# C lang path

---

> [!tip]
> C Language
> - Basics
> - Data Types
> - Pointers
> - Arrays
> - Structs
> - Memory Allocation
> - Strings
> - Function Pointers

1. ## C LANGUAGE (for DSA + Systems)

### C Basics

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

#### Comments

- commments - `//` for single line comments (everything after them will be ignored), `/**/` multiline in between the asterics will be ignored

#### Variables

> [!tip] You can declare variables without initilizing them.

- declaring variables:
```c
    type variableName = value;
    
    int myNum = 15;

    // declare variable without assigning a value
    int test;

    // assign a value later
    test = 21;

    // declare multiple variables at once
    int a, b, c;

    // initialize multiple variables in one line
    a = 10; b = 20; c = 30;
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

- reassigning a constant
```c
const int x = 5;
x = 10;

// GCC typically reports:
// error: assignment of read-only variable 'x'

// Clang typically reports:
// error: cannot assign to variable 'x' with const-qualified type 'const int'
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
```c
// invalid variable names
int 1invalid = 6;
int invalid-name = 7;
int invalid&name = 8;
```



> 1.2. Data Types & Memory Layout

#### Data types

Base data types:
- integers
- floating points
- characters
- booleans
- the void type - this is the C way of representing the absence of data

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


#### Type Conversion

Convert a value from one type to another.

Type of conversion in C:
- *Implicit Conversion* (automatically) - done automatically by the compiler when you assign a value of one type to another
Example:
```c
// automatic conversion: int to float
float myFloat = 9;

printf("%f", myFloat); // 9.000000
```
- *Explicit Conversion* (manually) - done manually by placing the type in parenthesis () in front of the value.
```c
float sum = 5 / 2;
printf("%f", sum); // 2.000000 -> this is because 5 and 2 are integers

// manual conversion int to float
float sum = (float) 5 / 2;
printf("%f", sum); // 2.500000

int num1 = 5;
int num2 = 2;
float sum = (float) num1 / num2;
printf("%f", sum); // 2.500000
```

- characters
```c
// converting characters to integers (ASCII code)
char my_char = 'A';

int letter_a_code = my_char;
printf("The ASCII code for the letter A is: %d\n", letter_a_code);


// get the integer value of a numerical character
char my_num_char = '7';
int my_num = my_num_char - '0';
printf("My converted number is: %d\n", my_num);

// converting integers to characters
char converted_a = letter_a_code; // implicit cast
printf("The letter corresponding to code %d is: %c\n", letter_a_code, converted_a);

char explicitly_converted_a = (char) letter_a_code; // explicit cast
printf("Explicitly typecasted: %c\n", explicitly_converted_a);
```

- integers - positive or negative whole numbers
- integer types:
    - short - 2 bytes long
    - int - usually 4 bytes long
    - long - often 4 bytes, on 64-bit systems can be 8 bytes
    - long long - always 8 bytes in size
- integer type qualifiers
    - signed - can be negative or positive
    - unsigned - always positive
```c
// get the byte size of an int type
int size_of_short = sizeof(short);
```

> [!warning] Going from larger data type to a smaller data type (e.g. long to short) might cause some data loss. Avoid this!


- floating points
- floating point types:
    - floats - smaller, floats can be created via the "f" suffix and are 4 bytes in length
    - doubles - doubles are 8 bytes in length
    - long double - not often used, 16 bytes in length, suffix with "L"

> [!warning] C doesnt support unsigned floating points! Everything is signed.

#### Constants

- constants in C make the variable *unchangeable* and *read-only*
- when you declare a variable it *must* be assigned with a value
- it is not mandatory but it is a good practice to name your constants with uppercase

```c
const int myNum = 15;
```

#### Operators

Types:
- Arithmetic - common mathematical operations

> [!warning] When dividing two integers in C, the result will also be an integers. (10 / 3 gives 3). If you want a decimal result, use *float* or *double* values like 10.0 / 3

- Assignment - most assignment operators are just shorter ways of writing code.
```c
int x = 5;
x += 10;

// others: -= *= /= %= ...etc
```

- Comparison - the return value of a comparison operator is either 1 or 0 (true or false)
- Logical - used to determine the logic between variables or values, by combining multiple conditions
- Precedence - C follows order of operations rules to decide which part to calculate first

> [!warning] Always use () if you want to make sure the calculation is done in the order you expect.

Order highest to lowest
```c
() - parenthesis
* / %
+ -
> < >= <=
== !=
&&
||
=
```

#### Booleans

- in C the *bool* type is not a built-in data type, it was introduced in C99 and you need to import it:
```c
#include <stdbool.h>

bool test = true;
bool test2 = false;

// use the %d format specifier to print bool
// this is because 0 represents false and 1 (or any other number that is not 0) represents true

printf("%d", test); // 1
printf("%d", test2); // 0
```


#### Understanding identifiers

> [!tip] Variables are memory locations used for storing data!

1. Memory allocation basics
    - stack
    - heap
2. Stack-allocated memory - happens implicitly, C handles that for us
    - simple - automatic allocation and deallocation
    - determined at compile time
    - local to scope / fast access

```c
const int PI = 3.14f; // *const* type qualifier can be used to ensure that a variable cannot be reassigned
```

> [!tip] Use *const* as much as you can for variables that are not meant to change in value in order to be as explicit as possible!


#### If...Else

```c
if (condition) {

} else if (condition2) {

} else {

}
```

> Ternary operator
```c
variable = (condition) ? expressionTrue : expressionFalse;

// instead of:
int time = 20;
if (time < 18) {
    // 1
} else {
    // 2
}

// you can:
int time = 20;
(time < 18) ? // 1 : //2;
```

#### Switch statement

```c
switch (expression) {
    case x: 
        // code block
    break;
    case y: 
        // code block
    break;
    default:
        // code block
}
```

#### Debugging a C program

1. Common bugs
    - syntax errors and compilation errors
    - logical bugs - these you have to debug manually
    - memory management errors - harder to debug
    - off-by-one errors
    - using uninitialized variables
2. Debugging methods
    - print statements / logging
    - debugger


### Control flow and functions

#### While, Do/While

```c
while (condition) {
    // code
}

do {
    // code
} while (condition);
```

- the difference between while and do/while is the code execution. In while first the condition is being evaluated and then the code is executed.
In do/while the code is executed first and then the condition is being evaluated, the code always runs at least once.









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
