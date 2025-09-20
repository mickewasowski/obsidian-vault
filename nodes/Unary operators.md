---
aliases:
context:
- "[[Expressions and Operators]]"
---

# Unary operators

A unary operation is an operation with only one operand.

---
Unary operators are the special operators that consider a single operand and perform all the types of operations on that single operand.

1. Types of operators:
- unary plus
- unary minus
- prefix increments
- prefix decrements
- postfix increments
- postfix decrements


Examples:

```js
delete object.property;
delete object[propertyKey];
delete objectName[index];
```
Since `arrays` are just objects, it's technically possible to `delete` elements from them. However, this is regarded as bad practice - try to avoid it.

```js
const myFun = () => 5 + 2;
const shape = "round";
const size = 1;
const foo = ["Apple", "Mango", "Orange"];
const today = new Date();

typeof myFun; // returns "function"
typeof shape; // returns "string"
typeof size; // returns "number"
typeof foo; // returns "object"
typeof today; // returns "object"
typeof doesntExist; // returns "undefined"
```
