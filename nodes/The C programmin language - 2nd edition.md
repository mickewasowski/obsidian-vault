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

1.1 Getting started
- print `hello world`
```c
#include <stdio.h>

main()
{
    printf("hello world\n");
}
```
> save the above in a `hello.c` file and then compile it with *cc hello.c*. This will generate a `a.out` executable file.

>[!tip] every C program **must** have a `main` function somewhere. This is the starting point of your program.
