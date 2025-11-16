---
aliases:
context:
- "[[Asynchronous Javascript]]"
---

# Promises

A Promise is an object representing the eventual *completion* or *failure* of an asynchronous operation.
It acts as a placeholder for a value that will be available in the future.

---
### Quick summary

`async/await` makes asynchronous code look synchronous, using Promises under the hood, while `then/catch` handles async flow with chained callbacks.
The behavior is the same (in most cases); the syntax and mental model are different.


### Promise states

A Promise has three states:
- pending -> operation is ongoing
- fulfilled -> operation succeeded
- rejected -> operation failed
Once fulfilled or rejected, the state becomes **settled** and cannot change.


### Creating a Promise

```js
const promise = new Promise((resolve, reject) => {
  // Async operation
  if (success) resolve(value);
  else reject(error);
});
```

### Consuming a Promise

`then()`
```js
promise.then(result => {
  console.log(result);
});
```

`catch()`
```js
promise.catch(error => {
  console.error(error);
});
```

`finally()`
```js
promise.finally(() => {
  console.log("Done!");
});
```

### Promise chaining

Each `.then()` returns a new Promise -> enables chaining

```js
doSomething()
  .then(res => doNext(res))
  .then(final => console.log(final))
  .catch(err => console.error(err));
```

### Common Promise Utilities

`Promise.all()`
Waits for *all* Promises -> fails if one rejects

`Promise.allSettled()`
Waits for all -> *never fails*, returns status of each

`Promise.any()`
Returns the *first fulfilled* Promise -> rejects only if all fail


> async/await is a syntactic sugar, a friendlier way to work with Promises.

> [!tip] Promises prevent callback hell.
> They are eager - start running immediately.
> They always operate *asynchronously*, even when resolved instantly.
> Errors bubble through `.catch()` or `try/catch` with async/await.


> [!warning] The main difference between Promises with callbacks (`.then().catch()`) and async/await syntax is that await *pauses the execution* only inside the async function, where the Promise callback gets executed whenever the Promise resolves.

Example:
```js
console.log("Start");

// Example with .then()
fetch("/data1")
  .then(res => {
    console.log("Promise then: Data1 received");
  });

// Example with async/await
async function getData2() {
  console.log("Before await");
  const res = await fetch("/data2");
  console.log("After await: Data2 received");
}

getData2();

console.log("End");
```
When you call an async function with await, the calling function itself pauses until the inner async function resolves. But if you call an async function without await, it just returns a Promise immediately and the function keeps running.


### Difference between then/catch and async/await syntax

1. With async/await the code "looks" synchronous due to it's syntax. With multiple async steps the code remains easy to read.
With then chained callbacks the code becomes harder to read.
2. Under the hood `await` pauses the function until the Promise settles. Event loop is NOT blocked - only the async function gets paused.
3. Parallel vs. Sequential execution
    - using `async/await` incorrectly forces sequential execution
```js
const a = await doA();
const b = await doB();
```
    - promise.then chains can run in parallel as follows:
```js
Promise.all([doA(), doB()]);
```
    - you can use parallelism with async/await as follows:
```js
const promiseA = doA();
const promiseB = doB();

const [a, b] = await Promise.all([promiseA, promiseB]);
```

### Use cases

- Use `then` when:
    - you need to attach handlers dynamically
    - you're working with streams, event-style APIs, or simple one-liners
- Use `async/await` when:
    - you have complex async logic
    - you want clean control follow
    - you care about readability and maintainability
