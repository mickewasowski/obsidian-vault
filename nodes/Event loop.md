---
aliases:
context:
- "[[JavaScript]]"
- "[[Asynchronous Javascript]]"
---

# Event loop

Allows async operations without blocking the main thread.

---
JS is single-threaded, which means it can handle one task at a time.
However, it handles many tasks efficiently using the *event loop*, which enables asynchronous operations without blocking the main thread.

### Key components

- Call stack - where functions get executed in order (LIFO - last in, first out)
- Web APIs (background tasks) - browser or Node.js APIs like timers (`setTimeout`), HTTP requests, etc., that run outside the main thread
- Callback Queue (Task queue) - when async operations complete, their callbacks go here
- Microtask Queue - for high-priority tasks like Promise callbacks
- Event Loop - continuosly checks if the call stack is empty and moves tasks from queues to the call stack


### How the Event loop works

1. Execute all synchronous code directly on the call stack
2. After synchronous code, process all Microtasks (Promises, `process.nextTick` in Node.js) before handling other tasks
3. Take the next callback from the Callback queue (Task queue) (like those from `setTimeout`) and push it onto the call stack
4. Repeat this cycle continuosly

> This allows JS to perform non-blocking operations such as I/O, timers, and user interactions efficiently despite having a single thread.

Example execution order:
```js
console.log('Start');
setTimeout(() => console.log('Timeout callback'), 0);
Promise.resolve().then(() => console.log('Promise resolved'));
console.log('End');
```

Output will be:
```js
Start
End
Promise resolved
Timeout callback
```

The above demonstrates that:
- sync code (`Start`, `End`) runs first
- Promise callbacks (microtasks) run immediatily after sync code
- `setTimeout` callbacks run later (macro-task queue)
