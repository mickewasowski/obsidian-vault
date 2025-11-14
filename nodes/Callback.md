---
aliases:
context:
- "[[Asynchronous Javascript]]"
---

# Callback

A Callback is a function used as an argument to another function.

---
### Types of callbacks

1. Synchronous callbacks - called immediately afte the invocation of the outer functions with no intervening asynchronous tasks
2. Asynchronous callbacks - called at some point later, after an async operation has completed


> Examples of Synchronous callbacks are callbacks that are passed to:
- `array.map()`
- `array.forEach()`


> Example of Asynchronous callbacks are callbacks that are passed to:
- `setTimeout()`
- `setInterval()`
- `Promise.then()`
