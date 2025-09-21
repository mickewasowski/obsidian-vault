---
aliases:
context:
- "[[JavaScript]]"
---

# Functions

Blocks of code that execute whenever they are called. Used for reusing code.

---
A function is a block of code that is executed when the function is called.

> A function declaration refers to a function definition that exists as a standalone statement - not as an expression.
Function declaration / Function statement
```js
function funcName(param1, param2, ...args) {
    // Function's body
}
```


> A function expression refers to a function definition that exists as an expression and not as a standalone statement.
```js
var someName = function funcName(param1, param2, ...args) { // here funcName is optional
    // function's body
}
```
