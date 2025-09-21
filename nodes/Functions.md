---
aliases:
context:
- "[[JavaScript]]"
---

# Functions

Blocks of code that execute whenever they are called. Used for reusing code.

---
### Functions

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

### Function parameters

1. Default parameters - typically in JS function parameters default to `undefined`.
However, you can set a different default value depending on your needs.

```js
function multiply(a, b = 1) {
    return a * b;
}
```

2. Rest parameters - syntax `...args` allows us to represent an indefinite number of arguments as an array.
```js
function multiply(a, ...args) {
    return args.map((x) => a * x);
}

const arr = multiply(2, 1, 2, 3);
console.log(arr); // [2, 4, 6]
```
