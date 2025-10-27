---
aliases:
context:
- "[[Functions]]"
---

# IIFE

Immediately-Invoked Function Expression is a function that is executed immediately after it is created.

---
### Syntax
```js
(async () => {

    const x = 1;
    const y = 9;

    console.log(x + y); // 10
})();
```

IIFE also knows as self-executing anonymous function.
It contains two parts:
- a function expression
- immediately calling the function expression


### Use cases
- avoiding pollutiong the global namespace by creating a new `scope`
- creting a new async context to use `await` in a non-async context
- computing values with complex logic, such as using multiple statements as a single expression
