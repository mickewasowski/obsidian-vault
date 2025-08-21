---
aliases:
context:
- "[[JavaScript]]"
---

# Closures
The ability of a function to store a variable for further reference, even after the function has completed its execution.

---
A closure is a function that *remembers* the variables from the scope where it was created, even after that scope has finished executing.
You can think of it as a function carrying a "backpack" of the variables it needs from its outer environment.

```JavaScript
    function outer() {
      let counter = 0;   // a variable inside outer

      function inner() {
        counter++;       // inner "remembers" counter
        console.log(counter);
      }

      return inner;
    }

    const fn = outer();  // run outer once, get back inner
    fn(); // prints 1
    fn(); // prints 2
    fn(); // prints 3
```
Here's what happens:
- `outer()` runs once, creating a local variable `counter`
- it returns the function `inner`
- even though `outer()` has finished, the returned `inner` still *remembers* `counter` (because of the reference)
- that's the closure at work - the variable `counter` is kept alive inside `inner`s "backpack"


### Why are closure useful?

1. Data privacy / encapsulation
```js
    function makeSecret(secret) {
      return function() {
        return secret;
      };
    }

    const getSecret = makeSecret("shh...");
    console.log(getSecret()); // "shh..."
```
=> no one can change `secret` from outside

2. Factories (functions that create other functions)
```js
    function makeMultiplier(factor) {
      return function(x) {
        return x * factor;
      };
    }

    const double = makeMultiplier(2);
    const triple = makeMultiplier(3);

    console.log(double(5)); // 10
    console.log(triple(5)); // 15
```

3. Maintaining state without global variables


> [!tip] Closures keep variable alive because the **inner function still has a reference to them**, so the garbage collector cannot free them.

- in most languages with closures (js, python, etc.), variables normally "die" when the function that created them finishes execution
- but if a function defined *inside* that scope isreturned (or passed somewhere else), the runtime must preserve the environment so that inner function can still work
- this preserved environment is oftern called a *closure object* or *environmental record*

```js
    function outer() {
      let counter = 0;

      function inner() {
        counter++;
        console.log(counter);
      }

      return inner;
    }

    const fn = outer(); // inner closes over counter
```

- normally `counter` would disappear after `outer()` finishes
- but `inner` still references `counter`
- therefore, the JS engine keeps that variable alive inside a closure object
- as long as `fn` (the returned `inner`) exists, `counter` stays in memory


### Garbage collection point
- once there are *no more references* to the closure function, the closure environment (and its variables) becomes unreachable
- at that point, the garbage collector can reclaim the memory


### Lifecycle of closures
Closures live *as long as something is referencing them*. To "kill" the inner function and free its captured variables, you need to remove all references to it so that the garbage collector can reclaim them.

```js
    function outer() {
      let counter = 0;
      return function inner() {
        counter++;
        console.log(counter);
      };
    }

    let fn = outer();  // fn references the inner closure
    fn(); // 1
    fn(); // 2

    // "Kill" it:
    fn = null;  // remove reference
```
At this point:
- the closure (`inner`) has no more references
- its environment (`counter`) is no longer accessible
- the garbage collector can safely free them


> More ways to "kill" closures
1. Reassign or overwrite the reference
```js
    fn = undefined;
```

2. Limit scope intentionally
```js
    (function() {
      let fn = outer();
      fn();
    })();
    // fn goes out of scope after the IIFE finishes
```
The closure will be eligible for collection after the scope ends


3. Explicitly manage reference in data structures
If you store closures in arrays, maps, or objects, remove them when done:
```js
    let handlers = [];
    handlers.push(outer());
    // ...
    handlers[0] = null;  // allow GC
```

> [!warning] You don't directly "free" memory in JS (unlike C with `free()`), because it's garbage collected.
> All you can do is *ensure there are no reference left* to the closure, and the GC will handle the rest.



### Some **gotchas** that keep closures alive for longer than you'd expect

1. Event listeners that capture variables
```js
    function setup() {
      let bigData = new Array(1000000).fill("💾"); // huge array

      function handler() {
        console.log(bigData.length);
      }

      document.body.addEventListener("click", handler);
    }

    setup();
```
- here `bigData` is captured by the `handler` closure
- even though `setup()` finished, the event listener keeps a reference to `handler`, which in turn keeps `bigData` alive
- *memory leak* - unless you `removeEventListener`, that big array never gets freed

fix:
```js
    document.body.removeEventListener("click", handler);
```

2. Closures stored in long-lived objects
```js
    let store = {};

    function createCache() {
      let cache = [];
      return function(item) {
        cache.push(item);
      };
    }

    store.fn = createCache(); // closure stored in a global object
```
- now `store.fn` references the closure
- the closure holds onto `cache` forever
- as long as `store` exists, so does `cache`

fix: delete references when not needed
```js
    delete store.fn;
```

3. Loops with closures (classic bug)
```js
    let funcs = [];

    for (var i = 0; i < 3; i++) {
      funcs.push(function() {
        console.log(i);
      });
    }

    funcs[0](); // 3
    funcs[1](); // 3
    funcs[2](); // 3
```
- all closures share the same `i` from the outer scope (because `var` has function scope)
- they keep that variable alive until the loop finishes

fix: use `let` (block scoped) or an IIFE
```js
    for (let i = 0; i < 3; i++) {
      funcs.push(() => console.log(i));
    }
```

4. Timers holding onto closures
```js
    function start() {
      let bigObj = { data: new Array(1000000).fill("📦") };

      setInterval(() => {
        console.log(bigObj.data.length);
      }, 1000);
    }

    start();
```
- the interval closre keeps `bigObj` alive forever
- if you forget to `clearInterval`, memory usage grows

fix:
```js
    const id = setInterval(...);
    clearInterval(id);
```

> [!error] Closures don't *cause* leaks on their own - leaks happen when you forget to clean up references in long-lived structures (globals, listeners, timers, caches).
