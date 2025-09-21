---
aliases:
context:
- "[[Functions]]"
---

# Recursion

Recursion is when a function invokes itself.

---
As recursion happens, the underlying code of the recursive function gets executed again and again until a termination condition, called the *base case*, gets fulfulled.
You will find it is used a lot in the world of algorithms.


The idea is to break a big task into smaller versions of the same task until it reaches a **base case** (a condition that stops the recursion).

Example:
```js
function factorial(n) {
  if (n === 1) return 1;         // base case
  return n * factorial(n - 1);   // recursive call
}

console.log(factorial(5)); // 120
```
How it works:
- `factorial(5)` -> `5 * factorial(4)`
- `factorial(4)` -> `4 * factorial(3)`
- `factorial(3)` -> `3 * factorial(2)`
- `factorial(2)` -> `2 * factorial(1)`
- `factorial(1)` -> returns `1`
The results multiply back up: `5 * 4 * 3 * 2 * 1 = 120`

Recursive case -> function keeps calling itself
Base case -> stops recursion and returns a value


Fibonacci implementation with recursion:
```js
function fibonacci(a) {
    if (a === 0) return 0;
    if (a === 1) return 1;

    return fibonacci(a - 1) + fibonacci(a - 2);
}
```
