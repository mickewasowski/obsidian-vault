---
aliases:
context:
- "[[JavaScript]]"
---

# Control flow

Control Flow is the order in which the computer executes statements in a script.

---
Computers read code from top to bottom, from the first line to the last line, unless it hits any statement that changes the control flow such as loops, conditionals, etc.

We can control the flow of the program through any of the below structures:
- sequential (default mode)
- conditional statements (if-else, switch)
- exception handling (error handling)
- loops and iterations

In JS we have three conditional statements:
- if
- if-else
- switch

In the parenthesis of an `if` statement you can use *anything* that can evaluate (can be coerced) to a boolean value.
You can use anything from primitives, to function calls, class instances, class properties, or even function calls on classes.

`switch` however is intended to evaluate an expression and match the expression's value against a series of `case` clauses.
`break` or `return` are necessary to avoid *fall-through*, unless of course it is intended and you want to handle a few cases with the same logic.
If no `case` matches it jumps to `default`.

The difference in performance between `if-else` and `switch` is mostly negligible.
However, here are some tips on when to use either:
- use `switch` for many discrete cases, especially when comparing the same variable
- use `if-else` for complex or varied conditions
