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


### Callback hell

Then callback hell is when we try to write asynchronous Javascript in a way where execution happens visually from top to bottom, creating a code that has a pyramid shape with many `})` at the end.

```js
loadScript('1.js', function(error, script) {

  if (error) {
    handleError(error);
  } else {
    // ...
    loadScript('2.js', function(error, script) {
      if (error) {
        handleError(error);
      } else {
        // ...
        loadScript('3.js', function(error, script) {
          if (error) {
            handleError(error);
          } else {
            // ...continue after all scripts are loaded (*)
          }
        });
      }
    });
  }
});
```
As calls become more nested, the code becomes deeper and increasingly more difficult to manage.
That's what sometimes is called "callback hell" or "pyramid of doom".
The "pyramid" of nested calls grows to the right with every asynchronous action. Soon it spirals out of control.

This can be fixed by providing separate functions as callbacks:
```js
loadScript('1.js', step1);

function step1(error, script) {
  if (error) {
    handleError(error);
  } else {
    // ...
    loadScript('2.js', step2);
  }
}

function step2(error, script) {
  if (error) {
    handleError(error);
  } else {
    // ...
    loadScript('3.js', step3);
  }
}

function step3(error, script) {
  if (error) {
    handleError(error);
  } else {
    // ...continue after all scripts are loaded (*)
  }
}
```
