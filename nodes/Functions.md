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
Default function parameters allow named parameters to be initialized with default values if no value or `undefined` is passed.

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


### Types of Functions
[[Arrow functions|Arrow Functions]]
[[IIFE]]


### Arguments object
Arguments object is an array-like object accessible inside functions that contains the values of the arguments passed to that function.
It is a local variable available in all non-arrow functions.

```js
function func1(a, b, c) {
    console.log(arguments[0]); // value of a
    console.log(arguments[0]); // value of b
    console.log(arguments[0]); // value of c
}
```

1. Use cases
- when the function is called with more parameters than they are declared to accept (instead of `...rest`)


> Each argument index can also be set or reassigned
Key points:
- non-strict mode: `arguments[i]` is linked to the corresponding named parameter, so updating one updates the other
- strict mode: this link is broken; reassigning `arguments[i]` does **not** affect the named parameter


[[Scope and function stack]]
[[Built-in functions]]

[[Recursion]]
