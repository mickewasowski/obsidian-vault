---
aliases:
context:
- "[[Expressions and Operators]]"
---


# Comma operators

---
The comma operator (`,`) lets you evaluate multiple expressions, returning the *value of the last one*.
It's often used in for-loops or compact expressions, but it's generally rare in real-world code because it can reduce readability.


> Best practice: Use the comma operator only when it improves clarity (like in `for` loops). Otherwise, splitting into multiple lines is usually more readable.


Examples:
```js
let x = (1, 2, 3);
console.log(x); //3
```

```js
for (let i = 0, j = 5; i < 5; i++, j--) {
  console.log(`i = ${i}, j = ${j}`);
}
```

```js
let a = 0;
let b = (a += 1, a += 2, a += 3);

console.log(a); // 6
console.log(b); // 6
```

```js
function demo() {
  return (console.log("first"), console.log("second"), "done");
}

console.log(demo());
// Logs:
// first
// second
// done
```
In this examples both `console.log` statements run, but `"done"` is the actual return value.
