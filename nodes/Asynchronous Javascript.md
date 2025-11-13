---
aliases:
context:
- "[[JavaScript]]"
---

# Asynchronous Javascript

Allows you to run potentially long-running tasks without blocking your program.

---
Javascript is single threaded. It works with a single _call stack_.
The call stack manages the execution of our program.
Javascript can handle a single task at a time.

### Web API

Some Web APIs allow us to offload long-running tasks to the browser.
When we call such API we're initiating this "offloading".
Such APIs are either callback based or promise based.
This process starts by adding the function invokation to the _Call stack_, this is just to register the callbacks and initiate the async task.
After doing that it can be popped off the call stack immediately so it doesn't wait for any data. In the background the browser starts some kind of process that eventually shows the user a popup for example. We don't know when the user might interact with it but that doesn't matter because it is not happening on the call stack and our entire website is still responsive in case other tasks need to run instead.


### Task queue

Once the user does interact with whatever popup the browser had shown, the respective callback (success/error) is pushed to the Task queue (also called Callback queue).
The Task queue holds Web API callbacks and event handlers to be able to be executed at some point in the future without disrupting our website's logic. If it were to be pushed directly to the Call stack it might interfere with whatever process is running at the moment in our website which might cause unknown behavior or bugs.
This is where the _Event loop_ comes into play. It checks frequently if the Call stack is empty, and only then it gets the first task from the Task queue and pushes it into the Call stack.

Example of such Web APIs are:
- `setTimeout` - the delay provided is the time it takes to get to the Task queue, it is not the time it takes to execute (if the Call stack is full it might take more time)
- `setInterval` - same as the above
- `getGeolocation`
- `fetch`
- `URL`
- `localStorage`
- `sessionStorage`
- `HTMLDivElement`
- `document`
- `indexedDB`
- `XMLHttpRequest`


### Microtask queue

Whenever we're working with Promises we're working with the Microtask queue.
It is a special queue dedicated to the `then()`, `catch()` and `finally()` callbacks, a function body execution after `await`, `queueMicrotask` callback, and the `new MutationObserver` callback.
The Event loop prioritizes the Microtask queue. It ensures the Call stack is empty, then proceeds with *all* Microtask queue tasks, and finally it moves to the Task queue tasks.

> A microtask can only call another microtask (it cannot create a task for the Task queue).


```js

fetch("https://www.example.com/something")
    .then((res) => console.log(res));
```
In the above example the following happens:
1. `fetch()` call is added to the Call stack
2. It is then added to the Web APIs offloading and removed from the Call stack
3. Once we receive the response from the Network call, the `then()` callback is added to the Microtask queue because it is a Promise reaction
4. Once the Call stack is empty the Event loop gets the task from the Microtask queue and pushes it to the Call stack


Example interview question:
```js
Promise.resolve()
    .then(() => console.log(1));

setTimeout(() => console.log(2), 10);

queueMicrotask(() => {
    console.log(3);
    queueMicrotask(() => {
        console.log(4);
    });
});

console.log(5);
```
// Correct answer: 5 1 3 4 2


> The priority is as follows:
> 1. Call stack
> 2. Once the Call stack is empty Microtask queue is in turn
> 3. Once the Microtask queue is empty it is Task queue's turn

> The Event loop always checks if the Call stack is empty before adding from the Microtask queue.
> Only after the Microtask queue is empty and nothing else is present in the Call stack it proceeds with the Task queue.
