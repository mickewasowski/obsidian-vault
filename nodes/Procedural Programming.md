---
aliases:
context:
- "[[Programming paradigm]]"
---

# Procedural Programming

Procedural programming is a programming paradigm where a program is organized as a sequence of procedures or functions that operate on data. The program runs step-by-step, following a set of instructions in order.

---
### Summary

Procedural programming focuses on procedures (functions) and step-by-step instructions to manipulate data.

### Key idea

You break a program into *procedures (functions)* that perform specific tasks, and the program calls these procedures in a defined sequence.


### Main characteristics

1. Step-by-steps execution - instructions run in order top to bottom
2. Use of procedures / functions - tasks are grouped into reusable blocks of code
3. Shared data - functions may read or modify shared variables
4. Control structures:
    Programs use things like:
        - `if` statements (decisions)
        - `for` / `while` loops (repetition)
        - function calls

Example:
```c
#include <stdio.h>

void greet() {
    printf("Hello!\n");
}

int main() {
    greet();
    printf("Welcome to procedural programming.\n");
    return 0;
}
```
In the above example:
- `main()` runs first
- it calls the procedure `greet()`
- each instruction executes in sequence


#### Languages that use procedural programming

- C
- Pascal
- Fortran
- BASIC

> Some modern languages like Python and Java also support procedural style, even though they support other paradigms too.

>[!tip] Procedural programming is like following a cooking recipe, each step happens in order, just like program instructions.
