---
aliases:
context:
- "[[JavaScript]]"
---


# JS Data types

Data type refers to the type of data that a JS variable can hold.

---
There are seven primitive data types in JS:
1. Number
2. BigInt
3. String
4. Boolean
5. Null
6. Undefined
7. Symbol


### String
Holds a sequence of characters. Any type of quotes can be used to contain a string but only if the starting quote is the same as the end quote.

### Number
Number in JS represents a floating-point number. Number constructor provides constants and methods which allow you to work with numbers.
Other types can be converted to numbers using `Number()`.

``` js
255 255.0 => the same
0xff // hexadecimal notation
0b11111111 // 255 in binary
0.255e3 // 255 in exponential notation
```

### Boolean
Holds one of two values - either `true` or `false`. These values are used to represent logical states and are essential in controlling the flow of a program.

### Undefined
Whenever a variable is declared but not initialized or assigned a value, then it is stored as `undefined`. Void functions return undefined.

### BigInt
Object that allows you to work with integers o arbitrary size.
Number can represent integers only within +-2^53, BigInt can handle integers far beyond this limit.
Particularly useful for applications requiring high precision with very large numbers, such as cryptography or scientific computations.

### Null
Signifies the deliberate absence of any object value.
*Deliberate absence* emphasises the intentional use of `null` to indicate that a variable does not point to any object.

### Symbol
Unique and immutable introduced in ES6.
Often used to create unique property keys for objects, ensuring no property key collisions occur.
Each Symbol value is distinct, even when multiple are created with the same description.
Their primary use case is to add hidden or special properties to objects that won't interfere with other properties or methods.
