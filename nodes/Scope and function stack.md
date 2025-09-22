---
aliases:
context:
- "[[Functions]]"
---

# Scope and function stack

---
### Scope
A space or environment in which a particular variable or function can be accessed or used.
Accessibility of this variable or function depends on where it is defined.
The scope is the current context of execution in which values and expressions are "visible" or can be referenced.
Scopes can also be layered hierarchically, so that child scopes have access to parent scope, but not vice versa.

In Javascript we have the following kinds of scopes:
- Global scope: the default scope for all code running in script mode
- Module scope: the scope for code running in module mode
- Function scope: the scope created with a function
- Block scope: the scope created with a pair of curly braces (a block)


### Function stack (Call stack)
The function stack is how the interpreter keeps track of its place in a script that calls multiple functions, like which function is currently executing and which functions within that function are being called.

- When a script calls a function, the interpreter adds it to the call stack and then starts carrying out the function
- any functions that are called by that function are also added to the call stack
- when a function is finished the interpreter removes it from the call stack and resumes execution where it left off
- if the stack takes up more space that it was assigned, a "stack overflow" error is thrown

OR in other words:
When a function makes a nested call, the following happens:

- The current function is paused.
- The execution context associated with it is remembered in a special data structure called execution context stack.
- The nested call executes.
- After it ends, the old execution context is retrieved from the stack, and the outer function is resumed from where it stopped.
