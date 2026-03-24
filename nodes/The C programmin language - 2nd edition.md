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
> save the above in a `hello.c` file and then compile it with *cc hello.c*. This will generate a `a.out` executable file.

>[!error] In the book the return type and return statement are missing from the above example. That is because C99 K&R allowed *implicit int*. Also the programs used to behave as if it returned success so that's why the return statement is omitted. 

>[!tip] every C program **must** have a `main` function somewhere. This is the starting point of your program.

> Steps:
1. save your program in a `.c` file
2. compile your code with `cc test.c` command
3. if successful the compiler will produce executable `a.out`
4. run the executable by typing `./a.out`

>[!tip] if you want a nicer output file name run this: `gcc test.c -o myprogram`
