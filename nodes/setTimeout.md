---
aliases:
context:
- "[[Asynchronous Javascript]]"
---


# setTimeout

You can initiate a function to execute after a set time.

---

Syntax:
```js
setTimeout(code, delay, param1, param2,...);
// the params are passed to the code function
```

> [!warning] `clearTimeout` will work only if the timeout task is still in the Web API tasks queue.
> Once tha task had reached the Task queue `clearTimeout` has no effect, the Event loop will eventually run it.
> Same is valid for `clearInterval`.
