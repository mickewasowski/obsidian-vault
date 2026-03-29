---
aliases:
context:
  - "[[C lang path]]"
  - "[[Software Development]]"
---

#wip

# The C programmin language - 2nd edition

Written by Brian W. Kernighan and Dennis M. Ritchie.

---

### Chapter 1

1.1. Getting started

- print `hello world`

```c
#include <stdio.h>

int main()
{
    printf("hello world\n");

	return 0;
}
```

> save the above in a `hello.c` file and then compile it with _cc hello.c_. This will generate a `a.out` executable file.

> [!error] In the book the return type and return statement are missing from the above example. That is because C99 K&R allowed _implicit int_. Also the programs used to behave as if it returned success so that's why the return statement is omitted.

> [!tip] every C program **must** have a `main` function somewhere. This is the starting point of your program.

> Steps:

1. save your program in a `.c` file
2. compile your code with `cc test.c` command
3. if successful the compiler will produce executable `a.out`
4. run the executable by typing `./a.out`

> [!tip] if you want a nicer output file name run this: `gcc test.c -o myprogram`

1.2. Variables and Arithmetic Expressions

- leaving comments (ignored by the compiler):

```c
/* this is a comment */
int main()
{
	/* some text
	some more text
	final text */
}
```

- defining variables:
  > All variables **must be declared** before they are used

```c
int main()
{
	int fahr, int celsius;
}
```

- defining while loop:

```c
int main()
{
	while (/* some check */) {
		/* some logic */
	}
}
```

> Variable types

- the size of the variables depends on the machine type (16-bit, 32-bit, 64-bit)

| type   |
| ------ |
| int    |
| float  |
| char   |
| short  |
| long   |
| double |

> Placeholders - they **must** match properly by number and type

```c
printf("%d\t%d\n", fahr, celsius);
```

- `%d` -> integer argument

> [!tip] If an arithmetic operator has one floating-point operand and one integer operand, the integer will be converted to a floating-point before the operation is done.
> Different floating types promote upward if you try mixing them: `int -> float -> double -> long double`

- formatting decimal numbers when printing:

```c
    printf("%3.0f", fahr); /* print the number at least 3 digits wide with NO numbers after the decimal point */

    printf("%6.1f", fahr); /* print the number at least 6 digits wide with one number after the decimal point */

    printf("%.2f", fahr); /* here the width is not constrained, it is specified to print 2 digits after the decimal point */

    /* `%f` says to print the number as floating point */
```

| symbol | what it does                                                       |
| ------ | ------------------------------------------------------------------ |
| %d     | print as decimal integer                                           |
| %6d    | print as decimal integer, at least 6 characters wide               |
| %f     | print as floating point                                            |
| %6f    | print as floating point, at least 6 characters wide                |
| %.2f   | print as floating point, 2 characters after decimal point          |
| %6.2f  | print as floating point, at least 6 wide and 2 after decimal point |
| %o     | octal                                                              |
| %x     | hexadecimal                                                        |
| %c     | character                                                          |
| %s     | string                                                             |
| %%     | % itself                                                           |



