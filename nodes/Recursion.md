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

Number to the power:
```js
function pow(x, n) {
    return (n === 1) ? x : (x * pow(x, n));
}
```

In terms of function execution no matter how many times a function calls itself,
each call is added to the *execution context stack* (or simply call stack).
``` js
Context: { x: 2, n: 1, at line 1 } pow(2, 1)
Context: { x: 2, n: 2, at line 5 } pow(2, 2)
Context: { x: 2, n: 3, at line 5 } pow(2, 3)
```

> Recursion, however, is memory costly because for the case of `pow(x, n)` we'd need memory for all n contexts.
In this case a loop-based algorithm is more memory-saving.

**Any recursion can be rewritten as a loop. The loop variant can usually be made more effective.**
